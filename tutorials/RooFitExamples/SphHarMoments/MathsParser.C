#include "MathsParser.h"
#include <string>
#include <sstream>
#include <iostream>
#include <limits>
//#include <utility>
#include<bits/stdc++.h>

namespace HS{
  namespace PARSER{

    using namespace std;

    string MathsParser::ToComponentsPDF(string str){

      str=StringReplaceAll(str," ","");//remove whitespace
      str=ReplaceSummations(str); //expand summations

      //change + -> : and * -> ; for RooComponentsPDF
      str=StringReplaceAll(str,"+",":");
      str=StringReplaceAll(str,"*",";");

      //Look for Parameters and functions
      //componet position
      size_t pos=0;
      //term position
      size_t tpos=0;
     
      string term("start");
      while(!term.empty()){
	term=NextComponentsTerm(str,pos,tpos);


	//case predefined
	if(CheckParameterList(term))
	  continue;
	if(CheckFunctionList(term))
	  continue;
	if(CheckFormulaList(term))
	  continue;
	//case function //must  be first in case contains ( or [
	if(StringContainsChar(term,'=')){
	  AddFormula(term);
	  continue;
	}
	cout<<" para ? "<<term<<endl;
	//case parameter
	if(StringContainsChar(term,'[')){
	  cout<<"YES"<<endl;
	  AddParameter(term);
	  continue;
	}
	//case function
	if(StringContainsChar(term,'(')){
	  AddFunction(term);
	  continue;
	}
	
      }
	  _pdfString="RooComponentsPDF::"+_name+"(0,"+_varsString+",="+str+"})";
	  return _componentsString;
    }
    string MathsParser::NextComponentsTerm(string str, size_t& pos, size_t& tpos){

      str+=":";//make sure we go to the end of str
      
      string component("start");
 
      //Look for term to next :
      size_t origpos=pos;
      component =StringToNext(str,pos,":")+";";

      
      while(component!=";"){
	string term("start");
	while(!term.empty()){
	  //look for term to next ;
	  term =StringToNext(component,tpos,";");
	  if(!term.empty()){
	    pos=origpos; //still got more terms
	    return term;
	  }
	  term =StringToNext(component,tpos,"");
	  if(!term.empty()){
	    pos=origpos; //still got more terms
	    return term;
	  }
	  
	}
	origpos=pos; //update origpos to new component
	component =StringToNext(str,pos,":")+";";//make sure we go to the end of str (+;)
	tpos=0;//move tpos back to start of next component
     }
      
     return string();
    }
    void MathsParser::AddParameter(string par){
      if(CheckParameterList(par)){
	cout<<"WARNING AddToParameterList already have a "<< StringToNext(par,"[")<<endl;
	return;
      }
      cout<<"ADDING "<<endl;
      //make list in  RooFit parameter format
      _parList.push_back(par);
      return; 
    }
   void MathsParser::AddFunction(string fun){
     if(CheckFunctionList(fun)){
       cout<<"WARNING AddToFunctionList already have a "<< StringToNext(fun,"(")<<endl;
       return;
     }
     //make list in  RooFit parameter format
     //Find which template this function belongs to
     string funcType;
     for(auto temp:_functionTemplates){
       if(regex_match(fun,temp.second))
     	 funcType=temp.first;
     }
     if(funcType.empty()){
       cout<<"WARNING  AddFunction no valid template for "<<fun<<endl;
       return;
     }
     _funList.push_back(funcType+"::"+fun);
      return ;
    }

    //e.g. AddFunctionTemplate("RooHSSphHarmonicRe","RealY_*_*(*,*)");
    void MathsParser::AddFunctionTemplate(string func,string temp){
      temp=StringReplaceAll(temp,"*","[a-zA-Z0-9]+");
      temp=StringReplaceFirst(temp,"(","\\(");
      temp=StringReplaceFirst(temp,")","\\)");
      
      regex regtemp(temp);
      _functionTemplates.push_back(std::make_pair<std::string,std::regex>(std::move(func),std::move(regtemp)));
    }
    
   void MathsParser::AddFormula(string form){
     if(CheckFormulaList(form)){
       cout<<"WARNING AddToFormulaList already have a "<< StringToNext(form,"=")<<endl;
	return;
      }
       //make list in  RooFit parameter format
      _formList.push_back(form);
      return ;
    }
    bool MathsParser::CheckParameterList(string par){
      for(auto& lpar:_parList){
	auto lparName=StringToNext(lpar,"[");	  
	auto parName=StringToNext(par,"[");
	if(parName==lparName)
	  return true;
      }
      return false;
    }
    bool MathsParser::CheckFunctionList(string fun){
      for(auto& lfun:_funList){
	auto lfunName=StringBetweenFirst(lfun,"::","(");
	auto funName=StringToNext(fun,"(");

	if(funName==lfunName)
	  return true;
      }
      return false;
    }
    bool MathsParser::CheckFormulaList(string fun){
      for(auto& lfun:_formList){
	auto lfunName=StringToNext(lfun,"=");
	auto funName=StringToNext(fun,"=");
	if(funName==lfunName)
	  return true;
      }
      return false;
    }
    string MathsParser::ReplaceSummations(string str){

      
      while(StringContainsString(str,"SUM")){
	string regex_sum = "SUM\\(\\w+\\[.*?\\]+?\\)"; //i.e. SUM(*){*}
	regex regsum(regex_sum);
	sregex_iterator it(str.begin(), str.end(), regsum);
 	
	auto sumover=it->str();// = SUM(*)
	auto endofsumover=it->position()+sumover.size();
	auto sum = WithinBrackets(str.substr(endofsumover,str.size()-endofsumover),'{'); //e.g. = {H_L}
	auto sumString=sumover+"{"+sum+"}";
	
	cout <<" GOING TO EXPAND "<<sumString<<" "<<sumover<<" "<<sum<<endl;

	auto expandString=ExpandSummation(sumString);
	if(expandString.back()=='+')expandString.pop_back(); 
	//	str=StringReplaceFirst(str,sumString,"("+expandString+")");
	str=StringReplaceFirst(str,sumString,expandString);

	cout<<"CURRENT STRING "<<str<<endl;
      }
      return str;

    }
    /////////////////////////////////////////////////////////////////////
    //Parse strings with SUM keyword
    //PRODUCT of sums After SUM look for balanced {}
    //e.g. string str = "SUM(L[0-4:1],M[0-L]){H0(L,M)*YLM(L,M)}SUM(L[4,7,20,1]){YLM(L,M)}";
    //NESTED sums
    // e.g. string str = "SUM(L[0-4]){SUM(M[0,2]){H0(L,M)*YLM(L,M)}}";
    string MathsParser::ExpandSummation(string str){
      //_DepthSummation++;
      
      string regex_sum = "SUM\\(\\w+\\[.*?\\]+?\\)"; //i.e. SUM(*)
      regex regsum(regex_sum);


      sregex_iterator it(str.begin(), str.end(), regsum);
      sregex_iterator it_end;
      uint endofsum=0;

      strings_std results;
      //Loop over factorised SUMs
      //check number of SUMS at this level
      int NSums=0;
      
      
      while(it != it_end) {
	if(endofsum>it->position()) //this SUM was nested
	  {++it;continue;}
	string result;
	auto sumover=it->str();// = SUM(*)
	auto endofsumover=it->position()+sumover.size();
	auto sum = WithinBrackets(str.substr(endofsumover,str.size()-endofsumover),'{'); //e.g. = {H_L}
	endofsum=endofsumover+sum.size();//position of end of this sum }

	//collect indices
	auto indices = GetSumIndices(sumover);

	//recurisvely loop over different indices
	//Order of indice is important
	sum=SumOverIndex(sum,indices,0);
     
	//Recursive nested SUMs
	if(StringContainsString(sum,"SUM"))
	  result+=ExpandSummation(sum);
	else
	  result+=sum;

	//add parenthesis
	//	if(result.back()=='+')result.pop_back(); //remove last +
	//if(NSums>1)results.push_back("("+result+")");
	results.push_back(result);
	
	//	cout<<"SUM     "<<" "<<results.back() <<endl;
	++it;
      }
      //if(result.back()=='+')result.pop_back(); //remove last +
        //Take product of SUMs 
      string finalResult;
      for(auto& tempResult:results){
	//	if(results.size()>1)
	//  finalResult+="("+tempResult+")";
 	finalResult+=tempResult;
     }
 
      // _DepthSummation--;
      return finalResult;
    }
    //////////////////////////////////////////////////////////////////////////////
    /// Find instances of sumIndices[Ni] in subject and sum over possible values of indice
    string MathsParser::SumOverIndex(string subject, SumIndices sumIndices,uint Ni){
      if(Ni>=sumIndices.size()) //terminate recursion
	return subject;
  
      auto& sumIndex=sumIndices[Ni];
  
      string label = sumIndex._label; //Going to replace this label

      auto vals = sumIndex._vals;   //with these values

      //check for possible dependency on other index of first and last index value
      int minVal=0;
      bool gotMinVal=false;
      if(!sumIndex._mindep.empty()){
	minVal=GetIndex(sumIndex._mindep,sumIndices)->_currval;
	gotMinVal=true;
      }
      int maxVal=0;
      bool gotMaxVal=false;
      if(!sumIndex._maxdep.empty()){
	maxVal=GetIndex(sumIndex._maxdep,sumIndices)->_currval;
	gotMaxVal=true;
      }
  
      regex reglabel(string("[\\W_]")+label+"[\\W_]"); //The label surrounded by punctuation or _  (make sure not a part of a word)
  
      string result;
      for(auto& val : vals){
	//check if valid val
	if(gotMinVal&&val<minVal) continue;
	if(gotMaxVal&&val>maxVal) continue;

	//index OK
	sumIndex._currval=val;
	string term = subject; //start with labelled string
	//find instances of the label regex
	std::smatch mch;
	std::regex_search(term,mch,reglabel);
	//loop over matching instances and replace lable with value
	while(mch.size()){
	  string sm=mch[0]; //get the first match for changing
	  string s0=mch[0]; //keep one for testing
	  sm.replace(1,label.size(),std::to_string(val));//replace char in pos 1 (label size char long) with val
	  //now replace in subject
	  size_t pos=0;
	  pos = term.find(s0, pos); //get position of this match in subject
	  term.replace(pos,s0.size(),sm); //and replace it with valued

	  //look for next match
	  std::regex_search(term,mch,reglabel);
	}
	term=SumOverIndex(term,sumIndices,Ni+1);
	if(!term.empty()){
	  //cout<<"TERM                  "<<label<<" "<<term<<endl;
	  result+=term; //add this summation term to string
	  if(result.back()!='+')result+="+"; //and sum with other terms
	}
      }
      //remove last +
      // result.pop_back();
      return result;
    }
    //////////////////////////////////////////////////////
    ///Parse indices which can be of form Label[min-max:increment]
    ///or Label[v1,v2,v3,...]
    ///returns vector of SumIndex structs
    SumIndices MathsParser::GetSumIndices(string str){
      cout<<" MathsParser::GetSumIndices "<<str<<endl;
      SumIndices indices;

      string regex_indice = "\\w+\\[.*?\\]+?";
      regex regindice(regex_indice);
 
      sregex_iterator it(str.begin(), str.end(), regindice);
      sregex_iterator it_end;
      while(it != it_end) {
	auto indstr=it->str();

	auto label=indstr.substr(0,indstr.find('['));

	auto ind=WithinBrackets(indstr,'[');

	SumIndex inde;
	inde._label=label;

    
	//case values v0,v1,v2,v3,...
	if(StringContainsChar(ind,',')){
	  auto values = Tokenize(ind,',');
	  for(auto& val:values)
	    inde._vals.push_back(std::stoi(val));

	  std::sort(inde._vals.begin(),inde._vals.end());
	}
    
	//case range min-max:increment
	if(StringContainsChar(ind,'-')){
	  //Check if format include increment !=1 [min-max:increment]
	  int increment=1;
	  if(StringContainsChar(ind,':')){
	    //get last element and convert to integer
	    auto splitColon=Tokenize(ind,':');
	    ind=splitColon.front(); //"min-max"
	    increment =  std::stoi(splitColon.back()); //"increment"
	
	  }
	  int first=INT_MAX;
	  int last=INT_MAX;

	  auto tokens = Tokenize(ind,'-');
	  int count=0;
	  //string like 0-5 will tokenize to 0 and 5
	  for(auto &token : tokens){
	    if(std::isdigit(token[0])){//standard numerical values
	      if(count==0) first = std::stoi(token);
	      else if(count==1) last =  std::stoi(token);
	      count++;
	    }
	    else{ //alpha value, could be another index label
	      if(count==0) inde._mindep = token;
	      else if(count==1)  inde._maxdep= token;
	      count++;
	    }
	  }
    
	  //look for dependents
	  if(first==INT_MAX||last==INT_MAX){
	    //got a dependent, look in previous indices
	    //a minimum?
	    if(!inde._mindep.empty()){
	      auto depsOn = GetIndex(inde._mindep,indices);
	      //get first value of index this depends on
	      first = depsOn->_vals.front();
	    }
	    //a maximum?
	    if(!inde._maxdep.empty()){
	      auto depsOn = GetIndex(inde._maxdep,indices);
	      //get first value of index this depends on
	      last = depsOn->_vals.back();
	    }
	  }
      
	  if(first==INT_MAX||last==INT_MAX)
	    cout<<"ERROR can not find first or last index value "<<ind<<endl;
	  else
	    //fill with the given range
	    for(int i=first;i<=last;i+=increment) {
	      inde._vals.push_back(i);
	    }
	  inde._currval=first;//initilaise current value
	}//case range

	indices.push_back(inde);
    
	++it;//next index label
      }
  
      return indices;
    }
    ////////////////////////////////////////////////////////////////////////
    ///return index with name "label"
    SumIndex* MathsParser::GetIndex(string label,SumIndices indices){

      for(auto& inde:indices)
	if(inde._label==label) return &inde;

      cout<<"Warning SumIndex GetIndex did not find Label, any summation index that depends on another must be listed after the one it depends on in SUM() "<<label<<endl;
      //didn;t find it 
      return nullptr;
    }
    ///////////////////////////////////////////////////////////////////////////////
    ///string helper functions
    vector<string> Tokenize(const string str,const char symbol){
      vector<string> tokens;
      std::istringstream iss(str);
      std::string token;
      //tokenize around the - to get first and last values
      while (std::getline(iss, token, symbol)){
	tokens.push_back(token);
      }	  
      return tokens;
    }
    bool StringContainsChar(const string str,const char symbol){
      return std::find(str.begin(), str.end(), symbol) != str.end();
    }
    bool StringContainsString(const string str1,const string str2){
      return str1.find(str2) != std::string::npos;
    }
    string StringReplaceAll(string str,string s1,string s2){
      if(StringContainsString(s2,s1)){
	cout<<"WARNING  StringReplaceAll s2 contains s1 so will start an infinite loop...."<< s1 <<" "<<s2<<endl;
	cout<<"         returning original string "<<str<<endl;
	return str;
      }
      while(StringContainsString(str,s1))
	str=StringReplaceFirst(str,s1,s2);
      return str;
    }
    string StringReplaceFirst(string str,string s1,string s2){
      size_t inde =0;
      inde=str.find(s1, inde);
      if (inde == std::string::npos) return str;
      /* Make the replacement. */
      str.replace(inde, s1.size(), s2);
      return str;
    }
    string StringToNext(string str,string s1){
      //string from start to s1
      //returns str if s1 does not exist
      size_t inde=0;
      auto result=StringToNext(str,inde,s1);
      if(result.empty())
	return str;
      return result;
    }
    string StringToNext(string str,size_t &pos,string s1){
      //string to next from pos
      //returns empty if no s1 between pos and end of string
      if (pos == std::string::npos) return string();//already at end
      size_t inde=pos;
      inde=str.find(s1, inde);
      if (inde == std::string::npos) return string();
      string result = str.substr(pos,inde-pos);
      pos=inde+1; 
      return result;
    }
    string StringBetweenFirst(string str,string s1,string s2){
     size_t pos1=0;
     pos1=str.find(s1, pos1)+s1.size();
     size_t pos2=0;
     pos2=str.find(s2, pos2);

     return str.substr(pos1,pos2-pos1);
    }
 
    ////////////////////////////////////////////////////////////////////////////////
    /// returns string within brackets of type bracket(='{','(','[') in string expr
    string WithinBrackets(const string expr,const char bracket){

      char closebracket='.';
      if(bracket=='{')closebracket='}';
      else if(bracket=='[')closebracket=']';
      else if(bracket=='(')closebracket=')';
      else cout<<"DO NOT RECOGNISE BRACKET "<<endl;
      uint open=0;
      for(auto& c:expr){
	if(c==bracket)
	  break;
	open++;
      }

      if(open==expr.size()) cout<<"Warning WithinBrackets Did not find a "<<bracket<<" in "<<expr<<endl;

      //now look for balanced closing bracket
      int n_open=1;
      for(uint i=open+1;i<expr.size();i++){

	if(expr[i]==bracket)
	  n_open++;
	if(expr[i]==closebracket)
	  n_open--;
	if(n_open==0){//found the balanced bracket return string inbetween
	 
	  return expr.substr(open+1,i-open-1);}
      }

      return expr;
    }
    void PrintStrings(const strings_std strs){
      for(auto& str:strs){
	cout<<str<<" ";
      }
      cout<<endl;
    }
  }//namespace PARSER
}//namespace HS

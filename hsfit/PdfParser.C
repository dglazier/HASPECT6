#include "PdfParser.h"
#include <string>
#include <sstream>
#include <iostream>
#include <limits>
//#include <utility>
#include<bits/stdc++.h>
#include <TFormula.h>
    
namespace HS{
  namespace PARSER{

    using namespace std;

    void PdfParser::AddParameter(string par){
      if(CheckParameterList(par)){
	cout<<"WARNING AddToParameterList already have a "<< StringToNext(par,"[")<<endl;
	return;
      }
      //make list in  RooFit parameter format
      _parList.push_back(par);
      return; 
    }
   void PdfParser::AddFunction(string fun){
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
     string full=funcType+"::"+fun;
     _funList.push_back(full); //for LoadFunctionVar
     _funNames[fun]=(StringToNext(fun,"(")); //For using just name
      return ;
    }

    //e.g. AddFunctionTemplate("RooHSSphHarmonicRe","RealY_*_*(*,*)");
    void PdfParser::AddFunctionTemplate(string func,string temp){
      temp=StringReplaceAll(temp,"*","[a-zA-Z0-9]+");
      temp=StringReplaceFirst(temp,"(","\\(");
      temp=StringReplaceFirst(temp,")","\\)");
      
      regex regtemp(temp);
      _functionTemplates.push_back(std::make_pair<std::string,std::regex>(std::move(func),std::move(regtemp)));
    }
    
   void PdfParser::AddFormula(string form){
     if(CheckFormulaList(form)){
       cout<<"WARNING AddToFormulaList already have a "<< StringToNext(form,"=")<<endl;
	return;
      }
       //make list in  RooFit parameter format
      _formList.push_back(form);
      return ;
    }
    bool PdfParser::CheckParameterList(string par){
      for(auto& lpar:_parList){
	auto lparName=StringToNext(lpar,"[");	  
	auto parName=StringToNext(par,"[");
	if(parName==lparName)
	  return true;
      }
      return false;
    }
    bool PdfParser::CheckFunctionList(string fun){
      for(auto& lfun:_funList){
	auto lfunName=StringBetweenFirst(lfun,"::","(");
	auto funName=StringToNext(fun,"(");

	if(funName==lfunName)
	  return true;
      }
      return false;
    }
    bool PdfParser::CheckFormulaList(string fun){
      for(auto& lfun:_formList){
	auto lfunName=StringToNext(lfun,"=");
	auto funName=StringToNext(fun,"=");
	if(funName==lfunName)
	  return true;
      }
      return false;
    }
    /////////////////////////////////////////////////////////////////////////
    ///Sum(L,i){Z_L_i}^2 =   Sum(L,i){F(A_L_i,A_L_i)*F(B_L_i,B_L_i)*F...} + 2*Sum(L1,L2<L1,i1,12<i1){F(A_L1_i1,A_L2_i2)*F(B_L1_i1,B_L2_i2)*F(C_L1_i1,C_L2_i2)*..}
    ///with F(C1,C2) = (ReC1*ReC2 + ImC1*ImC2) = ComplexSummationSquaredTerm
    string PdfParser::ReplaceComplexSummations(string str){
  
      while(StringContainsString(str,"SUM")){//SUM(*){1} + SUM(*){2} +...
	string strreg("SUM\\(\\w+\\[.*?\\]+?\\)\\{.*?\\}\\^2"); //i.e. SUM(*){*}^2
	regex regsum(strreg);

	sregex_iterator it(str.begin(), str.end(), regsum);

 	auto sumStr=it->str();// = SUM(L[],..){}^2
	//	auto endofsumover=it->position()+sumover.size();

	cout<<"SUMOVER "<<sumStr<<" "<<endl;
	//cout<<str.substr(endofsumover,str.size()-endofsumover)<<endl;
	//	auto sum = WithinBrackets(str.substr(endofsumover,str.size()-endofsumover),'{'); //e.g. = {H_L}
	auto sum = WithinBrackets(sumStr,'{'); //e.g. = {H_L}
	cout<<"SUM "<<sum<<endl;
       
	auto sumover=WithinBrackets(sumStr,'('); //L[],..
	cout<<sumover<<endl;
	//collect indices
	auto indices = GetSumIndices(sumover);
	cout<<"INDICES "<<indices.size()<<endl;

	//ConsolidateIndex consoInd(indices);
	
	auto indices1 = indices; //make a copy of indices
	//loop over indices and create 1 and 2 versions
	for(auto& ind  : indices1){
	  ind._label = ind._label + "1";
	}
	auto indices2 = indices; //make a copy of indices
	for(auto& ind  : indices2){
	  string orig=ind._label;
	  ind._label = orig + "2" ;
	}
	//Now see how many product terms we have in sum
	auto terms = Tokenize(sum,'*');
	if(terms.empty())//Just 1 term
	  terms.push_back(sum);
	
	//First part of expansion Sum(L,i){F(A_L_i,A_L_i)*F(B_L_i,B_L_i)*F...}
	string component1;
	for(auto &term  : terms ){//Protect string F£=ComplexSummationSquaredTerm
	  string newterm = "F£("+term+","+term+")";
	  component1 += newterm ; 
	  component1 += '*'; 
	}
	component1.pop_back(); //remove last *
	string result = "SUM("+sumover+"){"+component1+"}";
	

	//	Second part of expansion
	//2*Sum(L1,L2<L1,i1,12<i1){F(A_L1_i1,A_L2_i2)*F(B_L1_i1,B_L2_i2)*...}
	//Factor 2 will be gathered in definition of F£
	string component2;
	for(auto &term  : terms ){//Protect string F£=ComplexSummationSquaredTerm
	  string term1 = term;
	  for(UInt_t i=0;i<indices.size();i++)
	    term1=StringReplaceAll(term1,indices[i]._label,indices1[i]._label);
	  
	  string term2 = term;
	  for(UInt_t i=0;i<indices.size();i++){
	    auto newLabel= indices2[i]._label;
	    auto oldLabel= indices[i]._label;
	    term2=StringReplaceAll(term2,oldLabel,newLabel);

	  }
	  string newterm = "F£("+term1+","+term2+")";
	  component2 += newterm ; 
	  component2 += '*'; 
	}
	component2.pop_back(); //remove last *
	//change index labels in sumover
	string sumover1=sumover;
	//Just need to replace indices with indice +"1"
	for(UInt_t i=0;i<indices.size();i++){
	  sumover1=StringReplaceAll(sumover1,indices[i]._label,indices1[i]._label);
	}

	string sumover2=sumover;
	string prevInds;
	//Need to replace index with index +"2"
	//AND apply condition to FINAL indice that removes repeated
	//(actually associated or switched) terms being added twice
	//instead the factor 2 is applied in the summation formula
	// The necessary condtion :
	//e.g 3 indices L1+M1+K1-L2-M2 + ( L1+M1-L2-M2)  +(L1-L2) > K2
	//This satifies the inequalities combintation
	//L1>L2 => L1-L2>0
	//L1+M1 > (L2+M2)  O=> L1+M1-L2> M2  => L1+M1-L2-M2 > 0
	//L1+M1+K1 > L2+M2+K2  => L1+M1+K1-L2-M2 > K2
	//This is acquired in the prevInds string
	for(UInt_t i=0;i<indices.size();i++){
	  auto newLabel= indices2[i]._label;
	  auto oldLabel= indices[i]._label;
	  auto newLabel1=oldLabel+"1";
	  
	  sumover2=StringReplaceAll(sumover2,indices[i]._label,indices2[i]._label);
	  cout<<sumover2<<endl;
	  
	  //get the string specifiying the index criteria e.g. 0-3<L1 = range
	  size_t pos=0;
	  StringToNext(sumover2,pos,newLabel);
	  pos+=newLabel.size();
	  auto range = StringToNext(sumover2,pos,"]"); //e.g. L2[... ->]
     
	  if(i+1==indices.size() ){//apply condition to last index
	    auto replaceString = newLabel+"["+range+"]";
	    prevInds+=(prevInds+newLabel1);
	    range+="<"+prevInds+"-1"; //-1 =>less than not equal to
	    auto withString = newLabel+"["+range+"]";
	    //add final inequality condition to the last index
	    sumover2=StringReplaceFirst(sumover2,replaceString,withString);
	  }
	  //accumulate the final inequality 
	  prevInds+=(prevInds+newLabel1+"-"+ newLabel+"+");
	}
	result+="+SUM("+sumover1+","+sumover2+"){"+component2+"}";
	
 	cout<<"Currently "<<result<<endl;

	str=ReplaceSummations(result);
     }
      
      return str;
    }
    // string PdfParser::ReplaceConsolidatedSummations(string str,vector<ConsolidatedIndex> indices){

    //   for(auto& cind : indices){
    // 	SumOverConsolidatedIndex(str,cind);
    //   }
    // }
    // string PdfParser::SumOverConsolidatedIndex(string& subject, ConsolidatedIndex& sumIndex){
      
    //   std::vector<std::pair<string,int>> indEntry;
    //   while(indEntry=sumIndex.next()){ //loop over all index combinations

    // 	for(auto& labelVal   : indEntry){
    // 	  string label = labelVal->first;//Going to replace this label
    // 	  auto val = sumIndex._vals;   //with these values

 
    // 	  regex reglabel(string("[\\W_]")+label+"[\\W_]"); //The label surrounded by punctuation or _  (make sure not a part of a word)
  
    // 	  string result;
    // 	  for(auto& val : vals){
    // 	//check if valid val
    // 	if(gotMinVal&&val<minVal) continue;
    // 	if(gotMaxVal&&val>maxVal) continue;

    // 	//index OK
    // 	sumIndex._currval=val;
    // 	string term = subject; //start with labelled string
    // 	//find instances of the label regex
    // 	std::smatch mch;
    // 	std::regex_search(term,mch,reglabel);
    // 	//loop over matching instances and replace lable with value
    // 	while(mch.size()){
    // 	  string sm=mch[0]; //get the first match for changing
    // 	  string s0=mch[0]; //keep one for testing
    // 	  sm.replace(1,label.size(),std::to_string(val));//replace char in pos 1 (label size char long) with val
    // 	  //now replace in subject
    // 	  size_t pos=0;
    // 	  pos = term.find(s0, pos); //get position of this match in subject
    // 	  term.replace(pos,s0.size(),sm); //and replace it with valued

    // 	  //look for next match
    // 	  std::regex_search(term,mch,reglabel);
    // 	}
    // 	term=SumOverIndex(term,sumIndices,Ni+1);
    // 	if(!term.empty()){
    // 	  //cout<<"TERM                  "<<label<<" "<<term<<endl;
    // 	  result+=term; //add this summation term to string
    // 	  if(result.back()!='+')result+="+"; //and sum with other terms
    // 	}
    //   }
    //   }
      
 
    // }
    string PdfParser::ReplaceSummations(string str){
  
      while(StringContainsString(str,"SUM")){//SUM(*){1} + SUM(*){2} +...
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
    string PdfParser::ExpandSummation(string str){
       
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

	results.push_back(result);
	
	++it;
      }
      //Take product of SUMs 
      string finalResult;
      for(auto& tempResult:results){
 	finalResult+=tempResult;
     }
     return finalResult;
    }
    //////////////////////////////////////////////////////////////////////////
    /// Find instances of sumIndices[Ni] in subject and sum over
    /// possible values of indice
    string PdfParser::SumOverIndex(string subject, SumIndices sumIndices,uint Ni){
      if(Ni>=sumIndices.size()) //terminate recursion
	return subject;
  
      auto& sumIndex=sumIndices[Ni];
  
      string label = sumIndex._label; //Going to replace this label

      auto vals = sumIndex._vals;   //with these values

      //check for possible dependency on other index of first and last index value
      int minVal=-INT_MAX;
      bool gotMinVal=false;
      if(!sumIndex._mindep.empty()){
	for(auto& indMin:sumIndex._mindep){
	  auto indMinVal= EvalIndiceFormula(indMin,sumIndices);
	    if(minVal<indMinVal)minVal=indMinVal;
	}
	gotMinVal=true;
      }
      int maxVal=INT_MAX;
      bool gotMaxVal=false;
      if(!sumIndex._maxdep.empty()){
	for(auto& indMax:sumIndex._maxdep){
	  auto indMaxVal= EvalIndiceFormula(indMax,sumIndices);
	  if(maxVal>indMaxVal)maxVal=indMaxVal;
	}
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
    /////////////////////////////////////////////////////////////
    /// Check if this is valid index given conditions on indices
    // bool  PdfParser::IsValidIndex(SumIndices& sumIndices){

    //   for(auto& sumIndex: sumIndices){
    // 	int minVal=-INT_MAX;
    // 	bool gotMinVal=false;
    // 	if(!sumIndex._mindep.empty()){
    // 	  for(auto& indMin:sumIndex._mindep){
    // 	    auto indMinVal= EvalIndiceFormula(indMin,sumIndices);
    // 	    if(minVal<indMinVal)minVal=indMinVal;
    // 	  }
    // 	  gotMinVal=true;
    // 	}
    // 	int maxVal=INT_MAX;
    // 	bool gotMaxVal=false;
    // 	if(!sumIndex._maxdep.empty()){
    // 	  for(auto& indMax:sumIndex._maxdep){
    // 	    auto indMaxVal= EvalIndiceFormula(indMax,sumIndices);
    // 	    if(maxVal>indMaxVal)maxVal=indMaxVal;
    // 	  }
    // 	  gotMaxVal=true;
    // 	}
	
    //   }
    //   if(gotMinVal&&val<minVal) return false;
    //   if(gotMaxVal&&val>maxVal) return false;

    // }
    //////////////////////////////////////////////////////
    ///Parse indices which can be of form Label[min-max:increment]
    ///or Label[v1,v2,v3,...]
    ///returns vector of SumIndex structs
    SumIndices PdfParser::GetSumIndices(string str){
      cout<<" PdfParser::GetSumIndices "<<str<<endl;
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
    
	//case range min-max:increment<absMax>absMin
	//Note absMax and absMin can be used to limit an indice that depends
	//on another
	if(StringContainsChar(ind,'-')){
	  //Check if format include increment !=1 [min-max:increment]
	  int increment=1;
	  int gthan=INT_MAX;
	  int lthan=INT_MAX;
	  // if(StringContainsChar(ind,'>')){
	  //   //get last element and convert to integer
	  //   auto splitGt=Tokenize(ind,'>');
	  //   ind=splitGt.front(); //"min-max"
	  //   auto condVal=splitGt.back();
	  //   if(StringIsNumber(condVal))
	  //     gthan =  std::stoi(splitGt.back()); //
	  //   else{ //condition value is a string = >Label
	  //     //insert as maxdep
	  //     inde._mindep.push_back(condVal);
	  //   }
	  // }
	  // if(StringContainsChar(ind,'<')){
	  //   //get last element and convert to integer
	  //   auto splitLt=Tokenize(ind,'<');
	  //   ind=splitLt.front(); //"min-max"
	  //   auto condVal=splitLt.back();
	  //   if(StringIsNumber(condVal))
	  //     lthan =  std::stoi(splitLt.back()); //
	  //   else{ //condition value is a string = >Label
	  //     //insert as maxdep
	  //     inde._maxdep.push_back(condVal);
	  //   }
	  // }
	  if(StringContainsChar(ind,'<')||StringContainsChar(ind,'>')){
	    size_t pos=0; //position along string ind
	    
	    int gOrl=-1;
	    gOrl=StringWhichIsNext(ind,pos,">","<");
	    string conditions=ind;
	    if(gOrl==0)//>
	      ind=StringToNext(ind,">");
	    else
	      ind=StringToNext(ind,"<");

	    gOrl=-1;
	    pos=0;
	    
	    while((gOrl=StringWhichIsNext(conditions,pos,">","<"))!=-1){
	      if(gOrl==0){//>
		size_t pos0=pos;
	
		//check for another limit
		if((StringWhichIsNext(conditions,pos,">","<"))!=-1){
		  inde._mindep.push_back(conditions.substr(pos0,pos-pos0-1));

		}
		else{//if not take to the end of string
		  inde._mindep.push_back(conditions.substr(pos0,conditions.size()-pos0));
		}
		pos=pos0; 
	      }
	      else{//<
		size_t pos0=pos;
	
		//check for another limit
		if((StringWhichIsNext(conditions,pos,">","<"))!=-1){
		  inde._maxdep.push_back(conditions.substr(pos0,pos-pos0-1));

		}
		else{//if not take to the end of string
		  inde._maxdep.push_back(conditions.substr(pos0,conditions.size()-pos0));
		}
		pos=pos0; 
	      }
	    }
	  }
	  if(StringContainsChar(ind,':')){
	    //get last element and convert to integer
	    auto splitColon=Tokenize(ind,':');
	    ind=splitColon.front(); //"min-max"
	    increment =  std::stoi(splitColon.back()); //"increment"
	
	  }
	  int first=-INT_MAX;
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
	      if(count==0) inde._mindep.push_back(token);
	      else if(count==1)  inde._maxdep.push_back(token);
	      count++;
	    }
	  }
    
	  //look for dependents
	  //Replace with < and >
	  // if(first==-INT_MAX||last==INT_MAX){
	  //   //got a dependent, look in previous indices
	  //   //a minimum?
	  //   if(!inde._mindep.empty()){
	  //     for(auto& indMin: inde._mindep){
	  // 	auto depsOn = GetIndex(indMin,indices);
	  // 	//get last value of index this depends on
	  // 	//choose smallest advertised for now
	  // 	if(first<depsOn->_vals.front())first = depsOn->_vals.front();
	  //     }
	  //   }
	  //   //a maximum?
	  //   if(!inde._maxdep.empty()){
	  //     for(auto& indMax: inde._maxdep){
	  // 	auto depsOn = GetIndex(indMax,indices);
	  // 	//get last value of index this depends on
	  // 	//choose smallest advertised for now
	  // 	if(last>depsOn->_vals.back())last = depsOn->_vals.back();
	  //     }
	  //   }
	  // }
      
	  if(first==-INT_MAX||last==INT_MAX)
	    cout<<"ERROR can not find first or last index value "<<ind<<endl;
	  else
	    //fill with the given range
	    for(int i=first;i<=last;i+=increment) {
	      if(i>=lthan&&lthan!=INT_MAX) continue;
	      if(i<=gthan&&gthan!=INT_MAX) continue;
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
    SumIndex* GetIndex(string label,SumIndices indices){

      for(auto& inde:indices)
	if(inde._label==label) return &inde;

      cout<<"Warning SumIndex GetIndex did not find Label, any summation index that depends on another must be listed after the one it depends on in SUM() "<<label<<endl;
      //didn;t find it 
      return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////
    ConsolidateIndex::ConsolidateIndex(const SumIndices indices){

      _indices = indices;
      for(auto& ind: indices){
	cout<<ind._label<<" ";
	_labels.push_back(ind._label);
      }
      cout<<endl;

      _tempVals.resize(_indices.size());
      
      while(getValues(-1)){}; //Fill up entries

      for(auto& entryVals: _vals){
	for(auto& val:entryVals)
	  cout<<val<<" ";
	cout<<endl;
      }
      
    }
    bool ConsolidateIndex::getValues(int Nl){
      cout<<"ConsolidateIndex::GetValues(uint Nl) "<<Nl<<endl;
      if(Nl+1>=(int)_labels.size() )
	return false; //terminate
      
      //move on to next label
      Nl++;
      _indices[Nl].next();
      _tempVals[Nl]=_indices[Nl]._currval;
      if(Nl+1==(int)_labels.size()&&_vals.empty()){
	//push back the very first full one
	_vals.push_back(_tempVals);
      }
      while(!getValues(Nl)){
	if(!_indices[Nl].next()){ //no more indexes
	  _tempVals[Nl]=_indices[Nl]._currval;
	  return false;
	}
	//enter this value
	_tempVals[Nl]=_indices[Nl]._currval;
	_vals.push_back(_tempVals);
      }
      return true;
    }
    std::vector<std::pair<string,int>> ConsolidateIndex::next(){
      std::vector<std::pair<string,int>> result;
      if(_entry==(int)_vals.size()){
	_entry=0; //ready to start again
	return result;//but return empty to terminate
      }
	
      uint ii=0;
      for(auto& label : _labels)//for each label add a value with its name
	result.push_back(std::make_pair(label,_vals[_entry][ii++]));
      _entry++;
      return result;
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
      size_t inde =0;
     while(StringContainsString(str,s1)){
       inde=str.find(s1, inde);
       if (inde == std::string::npos) return str;
       str.replace(inde, s1.size(), s2);
       inde+=s2.size();
     }
     return str;
    }
    string StringReplaceFirst(string str,string s1,string s2){
      size_t inde =0;
      inde=str.find(s1, inde);
      cout<<"StringReplaceFirst(    "<<s1<<" "<<s2<<" "<<inde<<endl;
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
    int StringWhichIsNext(string str, size_t& pos, string s1,string s2){
      size_t pos1=pos;
      pos1=str.find(s1, pos1);
      size_t pos2=pos;
      pos2=str.find(s2, pos2);
      if (pos1 == std::string::npos&&pos2 == std::string::npos){
	pos=std::string::npos;
	return -1; //neither exist
      }
      if (pos1<pos2){
	pos=pos1+s1.size();
	return 0; //s1 nearer
      }
      pos=pos2+s2.size();
      return 1;  //s2 nearer
      
    }
    bool StringIsNumber(string str){
      for(auto& c:str)
	if(!std::isdigit(c))
	  return false;
      return true;
    }
    void PrintStrings(const strings_std strs){
      for(auto& str:strs){
	cout<<str<<" ";
      }
      cout<<endl;
    }

  
    int EvalIndiceFormula(string formula,SumIndices &indices){

      int icount=0;
      vector<int> vals;
      for(auto& ind:indices){ //loop over all possible indices
      	//replace name with TFormula parameter, [0],[1],...
      	formula=StringReplaceAll(formula,ind._label,"["+std::to_string(icount++)+"]");
      	vals.push_back(GetIndex(ind._label,indices)->_currval);
      }
      //create temporaty TFormula
    
      TFormula form("IndiceArithmetic",formula.data());
      for(int i=0;i<icount;i++)
      	form.SetParameter(i,vals[i]);

      return form.Eval(0);
      
    }
    // int MaxIndiceFormula(string formula,SumIndices &indices){

    //   int icount=0;
    //   vector<int> vals;
    //   for(auto& ind:indices){ //loop over all possible indices
    //   	//replace name with TFormula parameter, [0],[1],...
    //   	formula=StringReplaceAll(formula,ind._label,"["+std::to_string(icount++)+"]");
    //   	vals.push_back(GetIndex(ind._label,indices)->_cu);
    //   }
    //   //create temporaty TFormula
    //   cout<<"FORMULA "<<formula<<endl;
    //   TFormula form("IndiceArithmetic",formula.data());
    //   for(int i=0;i<icount;i++)
    //   	form.SetParameter(i,vals[i]);

    //   return form.Eval(0);
      
    // }
  }//namespace PARSER
}//namespace HS

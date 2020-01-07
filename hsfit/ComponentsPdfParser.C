#include "ComponentsPdfParser.h"
#include <string>
#include <sstream>
#include <iostream>
#include <limits>
//#include <utility>
#include<bits/stdc++.h>

namespace HS{
  namespace PARSER{

    using namespace std;

    string ComponentsPdfParser::ConstructPDF(string str){

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
	//case parameter
	if(StringContainsChar(term,'[')){
	  AddParameter(term);
	  continue;
	}
	//case function
	if(StringContainsChar(term,'(')){
	  AddFunction(term);
	  continue;
	}
	
      }
      //Change full function string to just name
      for (auto const& fun : _funNames){
	cout<<"REPLACE NAME "<< fun.first<<" "<<fun.second<<" "<<StringContainsString(str,fun.first)<<endl;
	str=StringReplaceAll(str,fun.first,fun.second);
      }
      
      _pdfString="RooComponentsPDF::"+_name+"(0,"+_varsString+",="+str+")";
      cout<<_pdfString<<endl;
      return _pdfString;
    }

    //////////////////////////////////////////////////////////////////////
    string ComponentsPdfParser::NextComponentsTerm(string str, size_t& pos, size_t& tpos){

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
 
  }//namespace PARSER
}//namespace HS

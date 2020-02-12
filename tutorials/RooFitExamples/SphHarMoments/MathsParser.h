////////////////////////////////////////////////////////////////
///
///Class:               MathsParser
///Description:   Expand mathematical expressions etc.
///

#pragma once
#include <regex>
#include <vector>
#include <string>


namespace HS{
  namespace PARSER{

    struct SumIndex;
    using SumIndices=vector<SumIndex>;
    
    using strings_std = std::vector<string>;
    
    class MathsParser {
      
      
    public:
    MathsParser(string name):_name(name){};
      
      //Deal with Summations
      string ReplaceSummations(string str);
      string ExpandSummation(string str);
      SumIndices GetSumIndices(string str);
      string SumOverIndex(string subject, SumIndices sumIndices,uint Ni);
      SumIndex* GetIndex(string label,SumIndices indices);

      //Deal with HS::FIT
      string ToComponentsPDF(string str);
      string NextComponentsTerm(string str, size_t& pos, size_t& tpos);
      void AddParameter(string par);
      void AddFunction(string fun);
      void AddFormula(string form);
      bool CheckFormulaList(string fun);
      bool CheckFunctionList(string fun);
      bool CheckParameterList(string par);

      void AddFunctionTemplate(string func,string temp);

      const strings_std GetParameters() const {return _parList;}
      const strings_std GetFunctions() const {return _funList;}
      const strings_std GetFormulas() const {return _formList;}

      string GetName(){return _name;}
      string GetPDF(){return _pdfString;}

      void SetVars(string vars){_varsString=vars;}
      
    private :

      strings_std _parList;
      strings_std _funList;
      strings_std _formList;

      string _name;
      string _pdfString;
      string _varsString;
      std::vector<std::pair<std::string,std::regex>> _functionTemplates;

      
      
    };//class MathsParser

    //struct to configure summation indexes
    struct SumIndex{
      string _label; //summation index
      string _maxdep; //can depend on other index
      string _mindep; //can depend on other index
      vector<int>_vals; //values of summation index
      int _currval=0; //keep track in case others depend on this
    };
   
    ///////////////////////////////////////////////////////////////////////////////
    ///string helper functions
    vector<string> Tokenize(const string str,const char symbol);
    bool StringContainsChar(const string str,const char symbol);
    bool StringContainsString(const string str1,const string str2);
    string WithinBrackets(const string expr,const char bracket);
    string StringReplaceFirst(string str,string s1,string s2);
    string StringReplaceAll(string str,string s1,string s2);
    string StringToNext(string str,size_t &pos,string s1);
    string StringToNext(string str,string s1);
    string StringBetweenFirst(string str,string s1,string s2);
    void PrintStrings(const strings_std strs);
  }
}

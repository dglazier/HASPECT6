

void testFormula(TString forma, std::vector<TString>& svars,std::vector<TString>& sranges){

  svars.clear();
  sranges.clear();
  for(Int_t i=0;i<forma.Sizeof();i++){
    if(TString(forma[i])=="@"){
      Int_t j=i;
       for(;j<forma.Sizeof();j++){
	if(TString(forma[j])=="["){
	  svars.push_back(forma(i+1,j-i-1));
	  i=j;
	  continue;
	}
	if(TString(forma[j])=="]"){
	  sranges.push_back(forma(i,j-i+1));
	  i=j;
	  break;
	}
	
      }
    }
  }
}

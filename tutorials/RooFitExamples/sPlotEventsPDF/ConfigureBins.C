//root  --hsfit ConfigureBins.C
{

  THSRooFit* RF=new THSRooFit("SF");
  RF->SetOutDir("outBins2/");
  ///////////////////////////////Load Variables
  RF->LoadAuxVars("Mmiss[0,10]");//Save Mmiss event between 0-10
  RF->LoadBinVars("Eg",3,3,3.3);//Make 3 bins in Eg between 3 and 3.3 
  RF->SetIDBranchName("fgID");  //Save ID variable fgID

  //MC Signal files
  TChain *chainmc=new TChain("MyModel","mcsignal");
  chainmc->Add("SigData.root");
  RF->MakeBinnedTrees(chainmc,"Sig");//Note "Sig" will be used to name PDF
  //MC BG files
  TChain *chainmcb=new TChain("MyModel","mcsignal");
  chainmcb->Add("BGData.root");
  RF->MakeBinnedTrees(chainmcb,"BG"); //Note "BG" will be used to name PDF
  //"Real" Data files
  TChain chain("MyModel");
  chain.Add("Data.root");
  RF->MakeBinnedTrees(&chain,"Data");

}

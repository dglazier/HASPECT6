 TList * Graphs=new TList();
 
//usage root --hsfit
//.L GraphParameters.C
//GraphParameters("out/","x") where x is a binned variable
//                           e.g. RF.Bins().LoadBinVar("x",4,3,4);
void GraphParameters(TString DirName,TString Var){



  TFile* file=new TFile(DirName+"DataBinsConfig.root");
  HS::Bins* DataBins=(HS::Bins*)file->Get("HSBins");
  TString BinName=DataBins->GetBinName(0);
  cout<<BinName<<endl;

  Int_t va= DataBins->GetAxisi(Var);
  TString AxisName=Var;

  // TList * Graphs=new TList();
  Graphs->SetName("AllGraphs");
  for(Int_t ib=0;ib<DataBins->GetN();ib++){
    TString redName=DataBins->GetBinName(ib);
    //Strip the variable we are plotting from the name
    //so we can find the relevent graph
    TString axisBin=redName(redName.Index(AxisName),TString(redName(redName.Index(AxisName)+AxisName.Sizeof()-1,redName.Sizeof())).First("_")+AxisName.Sizeof());
    redName.Replace(redName.Index(AxisName),TString(redName(redName.Index(AxisName)+AxisName.Sizeof()-1,redName.Sizeof())).First("_")+AxisName.Sizeof(),"");
    
 
    Int_t iP=DataBins->GetParti(va,axisBin);//index for this bin on this axis
    cout<<redName<<" "<<axisBin<<" "<<iP<<" "<<va<<endl;
    //Open the file with the results
    //TFile* fileR=new TFile(DirName+TString("Plots")+DataBins->GetBinName(ib)+".root");
    TFile* fileR=new TFile(DirName+"/"+DataBins->GetBinName(ib)+"/Results.root");
   if(!fileR->IsOpen()) continue;
   RooFitResult* result=dynamic_cast<RooFitResult*>(gDirectory->Get("HSFitResult"));
    file->cd();
    RooArgList Pars= result->floatParsFinal();
    //Loop over parameters getting values and error for graph
    TGraphErrors* graph=0;
    for(Int_t ipar=0;ipar<Pars.getSize();ipar++){
      //if graph doesn't exist yet create new one
      if(!(graph= dynamic_cast<TGraphErrors*>(Graphs->FindObject(redName+Pars[ipar].GetName())))){
	graph=new TGraphErrors(0);
	graph->SetNameTitle(redName+Pars[ipar].GetName(),redName+Pars[ipar].GetName());
	Graphs->Add(graph);
      }
      Int_t Npoint=graph->GetN();
      cout<<redName<<" "<<DataBins->GetAxis(va).GetBinCenter(iP+1)<<endl;
      graph->SetPoint(Npoint,DataBins->GetAxis(va).GetBinCenter(iP+1),((RooRealVar*)(&Pars[ipar]))->getVal());
      graph->SetPointError(Npoint,DataBins->GetAxis(va).GetBinWidth(iP+1)/2,((RooRealVar*)(&Pars[ipar]))->getError());
    }
    
    delete result;
    fileR->Close();
    delete fileR;
    //TGraphErrors* graph=Graphs->Get(redName);
  }

  TFile* fileG=new TFile(DirName+"ParGraphs"+Var+".root","recreate");
  Graphs->Write();
  fileG->Close();
  delete fileG;

  file->Close();
  delete file;

  return;


}

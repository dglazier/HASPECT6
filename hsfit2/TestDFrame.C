{
  TString tname("MyModel");
  TString fname("/work/Dropbox/HaSpect/dev/HASPECT6//RooFitExamples2/sPlotEventsPDF/Data.root");
  
  ROOT::RDataFrame df(tname.Data(),fname.Data(),{"fgID"});
  Weights weights;
  weights.LoadSaved("/work/Dropbox/HaSpect/dev/HASPECT6/RooFitExamples2/sPlotEventsPDF/outBins//Tweights.root","HSsWeights");
  weights.PrintWeight();

  using defs_t =   ROOT::RDF::RInterface<ROOT::Detail::RDF::RLoopManager, void > ;
 
  Int_t isp=0;
  auto applyWeights = [&weights,&isp](double id ) {
    // cout<<isp<<fgID<<endl;
    weights.GetEntryBinarySearch((Long64_t)id);
    return (float)(weights.GetWeight(isp));
  };

  //defs_t* current=&df;
  //vector<defs_t> vecDefs;
  /// auto latestDF = std::unique_ptr<RNode>;
  
  //  for(isp=0;isp<weights.GetNSpecies();isp++){
  for(isp=0;isp<1;isp++){
    auto def=current->Define(weights.GetSpeciesName(isp).Data(),applyWeights );
    //latestDF = std::make_unique<RNode>(latestDF->Define(weights.GetSpeciesName(isp).Data(), applyWeights)); 
  }
  latestDF->Snapshot("tt","test.root");
 }


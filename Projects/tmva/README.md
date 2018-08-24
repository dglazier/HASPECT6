# Guide to using THS Multivariate analysis
 
 ### FinalState setup
 
 The finalstate class outlines the particles involved in the reaction and the variables that will be used for the MVA analysis. The included examples shows the rough layout for this class.
 
 For the MVA analysis you must:
 * Pass the pointers to the THSParticles that will be used. Also pass the variables that will used for each particle, either by setting a default set or individually specifying them (NOTE: these should be    floats if they are to used for the MVA). For example:
   ```
   SetDefaultVariables({"P", "Th", "Phi", "Time", "Edep", "DeltaE", "Vz"});
   PrepAddParticle("Beam", &fBeam, {"P", "Time"});
   PrepAddParticle("Proton", &fProton);
   PrepAddParticle("Pip", &fPip);
   PrepAddParticle("PimL", &fPimL);
   PrepAddParticle("PimK", &fPimK);
 
   ```
   Here the beam and 4 other particles have been added. The beam has been added with specific variables whilst the remaining particles will use the default variables defined.
 * Add the methods to train in the form of method classes
   ```
   Method method;
   method.SetName("BDT0");
   method.SetType(TMVA::Types::kBDT);
   method.SetParameters("!H:!V:NTrees=1200:MinNodeSize=5%:MaxDepth=4:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20");
   fMVATrain.AddMethod(method);
   ```
   More methods can be added by creating seperate instances of the `Method` class and adding them.
 * Add any "splits", e.g. train different classifiers for each topology. For example, if the dataset had  4 different topologies, there could be added as follows:
   ```
   fMVATrain.AddSplit("Topo0", "Topo", &fTopoID, 0);
   fMVATrain.AddSplit("Topo1", "Topo", &fTopoID, 1);
   fMVATrain.AddSplit("Topo2", "Topo", &fTopoID, 2);
   fMVATrain.AddSplit("Topo3", "Topo", &fTopoID, 3);
   ```
   The first string is to identify the split and the second is the name of the branch in the TTree. The pointer is the same used to fill the TTree. The integer value refers to the expected of the variable for this split. Splits can also be set with mutiple criteria using vectors.
    
   The pointers will also need to be set for the application stage in `SetApplication`:
   ```
   fMVAApp.UpdateSplit("Topo0", &fTopoID);
   fMVAApp.UpdateSplit("Topo1", &fTopoID);
   fMVAApp.UpdateSplit("Topo2", &fTopoID);
   fMVAApp.UpdateSplit("Topo3", &fTopoID);
   ```
 * Define the output trees for training and application. This is done by adding branches to the TTree in `TMVAOutTree` and `FinalStateOutTree`.
 
 
 There are various other functions that should be left as are.
 
 
 ### RunFS<finalstate> setup
 
 The `RunFS<finalstate>` script outlines how to run the MVA. Again, some lines of code must be set:
 * Set the final state
 * Add the root files to the chain
   ```
   chain.Add("/path/data.root")
   ```
 * Set names for the output file and tree
 * Set the number of events:
   ```
   fs->SetNEvents(5000,1000,1000);
   ```
   Here the first number if the total number of signal events to generate, then the number of training signals and finally the number for testing. The code will load only the first N events until it reaches the total number, if using multiple data files it's recommended to load all the events and then a random subset will be used. This is done by setting the first value to `-1`.
 

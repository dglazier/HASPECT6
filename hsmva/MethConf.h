#ifndef HSMVA_METHCON_h
#define HSMVA_METHCON_h

#include <TMVA/Types.h>
#include <TMVA/Tools.h>
 
namespace HS{
  namespace MVA {
  
    class MethConf {
      
    public:
      
    MethConf(TMVA::Types::EMVA type,TString name,TString params):
      fName(name),fType(type),fParams(params){}
      
      virtual ~MethConf()=default;
      
      void SetName(TString name) {fName = name;};
      void SetType(TMVA::Types::EMVA type) {fType = type;};
      void SetParameters(TString params) {fParams = params;};
      
    
      TMVA::Types::EMVA fType; // method type for factory
      TString fName;           // name for saving dataset
      TString fParams;     // string of parameters for factory
      
    }; //class MethConf
    
    //Method Configurations taken from TMVAClassification.C
    //I am sure there is a beter way than this to provide
    //these defaults. Note if Meths is not const it crashes
    //om exiting ROOT
    struct MethodList{
      
      MethConf BDTA={TMVA::Types::kBDT,"BDTA","!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20"};
      
      MethConf BDTG={TMVA::Types::kBDT, "BDTG", "!H:!V:NTrees=1000:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.5:nCuts=20:MaxDepth=2"};
      
      MethConf BDTD={TMVA::Types::kBDT,"BDTD","!H:!V:NTrees=400:MinNodeSize=5%:MaxDepth=3:BoostType=AdaBoost:SeparationType=GiniIndex:nCuts=20:VarTransform=Decorrelate"};
      
      MethConf RuleFit={TMVA::Types::kRuleFit, "RuleFit","H:!V:RuleFitModule=RFTMVA:Model=ModRuleLinear:MinImp=0.001:RuleMinDist=0.001:NTrees=20:fEventsMin=0.01:fEventsMax=0.5:GDTau=-1.0:GDTauPrec=0.01:GDStep=0.01:GDNSteps=10000:GDErrScale=1.02"};
      
      MethConf MLP={TMVA::Types::kMLP, "MLP", "H:!V:NeuronType=tanh:VarTransform=N:NCycles=600:HiddenLayers=N+5:TestRate=5:!UseRegulator"};
      
      MethConf Cuts={TMVA::Types::kCuts, "Cuts", "!H:!V:FitMethod=MC:EffSel:SampleSize=200000:VarProp=FSmart"};
      
      MethConf SVM={ TMVA::Types::kSVM, "SVM", "Gamma=0.25:Tol=0.001:VarTransform=Norm"};

      MethConf MLPBFGS={ TMVA::Types::kMLP, "MLPBFGS", "H:!V:NeuronType=tanh:VarTransform=N:NCycles=600:HiddenLayers=N+5:TestRate=5:TrainingMethod=BFGS:!UseRegulator" };
 
   
      MethConf PDEFoamBoost={ TMVA::Types::kPDEFoam, "PDEFoamBoost",
                           "!H:!V:Boost_Num=30:Boost_Transform=linear:SigBgSeparate=F:MaxDepth=4:UseYesNoCell=T:DTLogic=MisClassificationError:FillFoamWithOrigWeights=F:TailCut=0:nActiveCells=500:nBin=20:Nmin=400:Kernel=None:Compress=T"  };
 
      MethConf KNN={ TMVA::Types::kKNN, "KNN",
                           "H:nkNN=20:ScaleFrac=0.8:SigmaFact=1.0:Kernel=Gaus:UseKernel=F:UseWeight=T:!Trim" };
 
      MethConf PDEFoam={ TMVA::Types::kPDEFoam, "PDEFoam",
                           "!H:!V:SigBgSeparate=F:TailCut=0.001:VolFrac=0.0666:nActiveCells=500:nSampl=2000:nBin=5:Nmin=100:Kernel=None:Compress=T" };
 
      MethConf Likelihood={ TMVA::Types::kLikelihood, "Likelihood",
                           "H:!V:TransformOutput:PDFInterpol=Spline2:NSmoothSig[0]=20:NSmoothBkg[0]=20:NSmoothBkg[1]=10:NSmooth=1:NAvEvtPerBin=50"};

      MethConf LikelihoodD={  TMVA::Types::kLikelihood, "LikelihoodD",
                           "!H:!V:TransformOutput:PDFInterpol=Spline2:NSmoothSig[0]=20:NSmoothBkg[0]=20:NSmooth=5:NAvEvtPerBin=50:VarTransform=Decorrelate"};

      MethConf PDERS={ TMVA::Types::kPDERS, "PDERS",
                           "!H:!V:NormTree=T:VolumeRangeMode=Adaptive:KernelEstimator=Gauss:GaussSigma=0.3:NEventsMin=400:NEventsMax=600" };

      MethConf PDERSD={ TMVA::Types::kPDERS, "PDERSD",
                           "!H:!V:VolumeRangeMode=Adaptive:KernelEstimator=Gauss:GaussSigma=0.3:NEventsMin=400:NEventsMax=600:VarTransform=Decorrelate"};

      MethConf CFMlpANN={ TMVA::Types::kCFMlpANN, "CFMlpANN", "!H:!V:NCycles=200:HiddenLayers=N+1,N" };

      MethConf TMlpANN={  TMVA::Types::kTMlpANN, "TMlpANN", "!H:!V:NCycles=200:HiddenLayers=N+1,N:LearningMethod=BFGS:ValidationFraction=0.3" };
 
      
    }; //struct Meths

    static const MethodList Meths;

    class DNNConf : public MethConf{

    public:

      DNNConf()=default;
    DNNConf(TString name):MethConf(TMVA::Types::kDNN,name,"")
	{
	  SetLayout();
	  DefaultTrainingStrategy();
	  SetOptions();
	}
      
      virtual ~DNNConf()=default;
      
      void Configure(){
	fParams=fOptions+":"+fLayout+":"+fTrainingStrategy;
	cout<<"DNNConf::Configure "<<fParams<<endl;
      };
      void ConfigureGPU(){
	fOptions.ReplaceAll("CPU","GPU");
	fParams=fOptions+":"+fLayout+":"+fTrainingStrategy;
	cout<<"DNNConf::Configure "<<fParams<<endl;
      };
  
     void SetOptions(TString options= "!H:V:ErrorStrategy=SUMOFSQUARES:VarTransform=G:WeightInitialization=XAVIERUNIFORM:Architecture=CPU"){fOptions=options;}
  
     //      void SetOptions(TString options= "!H:V::VarTransform=G:WeightInitialization=XAVIERUNIFORM:Architecture=CPU"){fOptions=options;}
      
      void SetLayout(TString layout="Layout=TANH|50,Layout=TANH|50,Layout=TANH|50,LINEAR"){fLayout=layout;}
      
      void SetTrainingStrategy(TString st){fTrainingStrategy=st;}
      
      void DefaultTrainingStrategy(){
	TString training0("LearningRate=1e-2,Momentum=0.5,Repetitions=1,ConvergenceSteps=20,BatchSize=50,"
			  "TestRepetitions=10,WeightDecay=0.01,Regularization=NONE,DropConfig=0.2+0.2+0.2+0.,"
			  "DropRepetitions=2");
	TString training1("LearningRate=1e-3,Momentum=0.9,Repetitions=1,ConvergenceSteps=100,BatchSize=50,"
			  "TestRepetitions=5,WeightDecay=0.01,Regularization=L2,DropConfig=0.1+0.1+0.1,DropRepetitions="
			  "1");
	TString training2("LearningRate=1e-4,Momentum=0.3,Repetitions=1,ConvergenceSteps=10,BatchSize=50,"
			  "TestRepetitions=5,WeightDecay=0.01,Regularization=NONE");
	
	TString trainingStrategyString("TrainingStrategy=");
      	trainingStrategyString += training0 + "|" + training1 + "|" + training2;
	//	trainingStrategyString += training0 + "|" + training1 ;
	//trainingStrategyString += training1 ;
	SetTrainingStrategy( trainingStrategyString);
      }

      
      TString fTrainingStrategy;
      TString fLayout;
      TString fOptions;
    };//class DNNConf
  }//namespace MVA
}//namespace HS
#endif // HSMVA_METHODCONFIGURE

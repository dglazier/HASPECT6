//run with root --THSSkeleton.C CreateMyFinalState.C
{
  THSSkeleton* sk=new THSSkeleton();
  //Give your project a name
  sk->SetFinalState("2Pi",kTRUE);  //creating the final state class 
  //Set the detected particle combinations you will analyse
  sk->SetFinalStateTopo("e-:pi+:pi-:proton,e-:pi+:proton,e-:pi-:proton,e-:pi+:pi-");
  //Set the actual final state particles of the reaction
  //These will just be used as the data member names, for example
  sk->SetFinalStateParts("Electron:e-,Proton:proton,Pip:pi+,Pim:pi-,Pi0:pi0");
   //define any parent particles that may have decayed, for example
  sk->SetFinalStateParents("Omega:omega;Pip;Pim;Pi0");
  //Uncomment for CLAS12 functionality
  sk->SetCLAS12();
 //Make some code
  sk->CreateMyFinalState();
}

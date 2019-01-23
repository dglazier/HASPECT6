//run with root --THSSkeleton.C CreateMyFinalStateEl.C
{
  THSSkeleton* sk=new THSSkeleton();
  //Give your project a name
  sk->SetFinalState("El",kTRUE);  //creating the final state class 
  //Set the detected particle combinations you will analyse
  sk->SetFinalStateTopo("e-,e-:proton");
  //Set the actual final state particles of the reaction
  //These will just be used as the data member names, for example
  sk->SetFinalStateParts("Electron:e-,Proton:proton");
   //define any parent particles that may have decayed, for example
  //Uncomment for CLAS12 functionality
  sk->SetCLAS12();
 //Make some code
  sk->CreateMyFinalState();
}

//run with root  CreateMyFinalState.C
{
  HS::CLAS12Skeleton sk;
  //Give your project a name
  sk.SetFinalState("WillThisWork");  //creating the final state class 
  //Set the actual detected particles of the reaction
  //These will just be used as the data member names, for example
  sk.SetFinalStateParts("Electron:e-, Proton:proton, Pip:pi+, Pim:pi-");
  //Set the detected particle combinations you will analyse
  sk.SetFinalStateTopo("Electron:Proton:Pip:Pim, Electron:Proton:Pip, Electron:Proton:Pim");
   //define any parent particles that may have decayed, for example
  sk.SetFinalStateParents("Rho:rho0;Pip;Pim");
  //Make some code
  sk.MakeCode();
}

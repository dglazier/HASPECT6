//run with root  CreateMyFinalState.C
{
  HS::FSSkeleton sk;
  //Give your project a name
  sk.SetFinalState("WillThisWork");  //creating the final state class 
  //Set the detected particle combinations you will analyse
  sk.SetFinalStateTopo("");
  //Set the actual final state particles of the reaction
  //These will just be used as the data member names, for example
  sk.SetFinalStateParts("");
   //define any parent particles that may have decayed, for example
  sk.SetFinalStateParents("");
  //Make some code
  sk.MakeCode();
}

/** \file CreateSelector.C
 * 
 * Macro to generate a TSelector
 * using the THSSkeleton class
 * 
 * Usage:
 * root --hssel CreateSelector.C
 * 
 */

void CreateSelector(){
	
	THSSkeleton* sk = new THSSkeleton();
	
	sk->SetHisto();   //Going to make histograms
	sk->SetNewTree();   //Going to make new tree
	
	sk->SetFinalState("THS2Pi"); //Give final state class name
	
	sk->CreateSelector("Process","/home/dglazier/clas12data/Andrea/Run004280/out_clas_004280.evio.0_9.hipo.root","HSParticles"); //create selector with all specifications
	
};

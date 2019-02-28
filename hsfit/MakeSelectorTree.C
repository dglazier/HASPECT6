
{

  auto filetree=FiledTree::Recreate("bins","BinIndices.root");
  auto tree=filetree->Tree();

  Int_t ib=0; 
  tree->Branch("bindex",&ib,"bindex/I");
  for(ib=0;ib<4;ib++)
    tree->Fill();

  filetree.reset();  
  tree.reset();
}

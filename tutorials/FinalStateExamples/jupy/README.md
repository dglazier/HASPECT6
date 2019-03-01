#Analysis of the CLAS12 2 pion final state

## Prerequisits

Assume HSCODE is set and rootrc is correct.
Assume CLAS12TOOL is set and Lz4 is compiled.

setenv HSEXP $HSCODE/hsexperiments/clas12tool

mkdir my/Pi2/dir
cd my/Pi2/dir

cp $HSCODE/hsskeleton/jupyter/CreateMyFinalState.ipynb .
cp $HSCODE/hsskeleton/jupyter/DevelopMyFinalState.ipynb  .
cp $HSCODE/hsskeleton/jupyter/Run_CLAS12_HIPO.ipynb  .

root --notebook &

Open CreateMyFinalState.ipynb and floow instructions.
     You will need to change FSSkeleton to CLAS12Skeleton


Once you have finished CreateMyFinalState and DevelopMyFinalState you can open Run_CLAS12_HIPO and try running (you will need a hipo file!)

Then you can try using the data frame based plotting notebook

cp $HSCODE/hsdf/jupyter/PlottingTemplate.ipynb Plotting.ipynb


#Analysis of the CLAS12 2 pion final state

## Prerequisites

ROOT 6.14+ with jupyter installed :

https://root.cern.ch/how/how-create-rootbook

Assume HSCODE is set and rootrc is correct.

See README https://github.com/dglazier/HASPECT6/tree/hsfit

Assume CLAS12TOOL is set and Lz4 is compiled, if not :

see https://github.com/dglazier/Clas12Tool/tree/hipo34

    setenv CLAS12TOOL /clas12/tool/directory
    setenv HSEXP $HSCODE/hsexperiments/clas12tool

If you are using hipo4 files then also

   setenv USE_HIPO4 1

mkdir my/Pi2/dir

cd my/Pi2/dir

cp $HSCODE/hsskeleton/jupyter/CreateMyFinalState.ipynb .

cp $HSCODE/hsskeleton/jupyter/DevelopMyFinalState.ipynb  .

cp $HSCODE/hsskeleton/jupyter/Run_CLAS12_HIPO.ipynb  .

root --notebook &

Open CreateMyFinalState.ipynb and follow instructions.
     You will need to change FSSkeleton to CLAS12Skeleton


Once you have finished CreateMyFinalState and DevelopMyFinalState you can open Run_CLAS12_HIPO and try running (you will need a hipo file!)

Then you can try using the data frame based plotting notebook

cp $HSCODE/hsdf/jupyter/PlottingTemplate.ipynb Plotting.ipynb


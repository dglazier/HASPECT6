## HSCODE should be set to HASPECT6 directory
## CLAS12TOOLS should be set to clas12tools directory
##   git clone --recurse-submodules https://github.com/gavalian/Clas12Tool
##   cd Clas12Tool/ ; make ;

setenv RHIPO $HSCODE/ExtraPackages/rhipo3
setenv CHIPO $CLAS12TOOLS/Hipo
setenv LZ4_h $CLAS12TOOLS/Lz4/lib
setenv LD_LIBRARY_PATH "$LD_LIBRARY_PATH":"$LZ4_h"

alias hipo2root root -l $RHIPO/Hipo2Root.C 
alias allhipo2root root -l $RHIPO/Hipo2Root.C $RHIPO/ConvertAll.C

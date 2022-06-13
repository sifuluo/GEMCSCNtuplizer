# GEMCSCNtuplizer

Credit of the Matcher goes to GEMCode project (https://github.com/gem-sw/GEMCode)

After set up the CMSSW environment and have L1Trigger folder ready.
If not, one can always do

    git cms-addpkg L1Trigger/CSCTriggerPrimitives
  
to set up the L1Trigger folder and CSCTriggerPrimitives is intensively used by this project too.
Then to set up the Ntuplizer:

    cd $CMSSW_BASE/src/L1Trigger
    git clone git@github.com:sifuluo/GEMCSCNtuplizer.git
    scram b -j 8

Then the EDAnalyzer should be set up.

In 

  test/Project/
  
lies the executive scripts to run.

Use the script

    cmsRun NtuplizeSIM.py
    
to run the ntuplizer. Change the parameters as you need.

Another python script

    python MakeSubmission.py

can easily make the folders and submission script needed on lxplus.

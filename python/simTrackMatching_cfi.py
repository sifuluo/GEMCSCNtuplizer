import FWCore.ParameterSet.Config as cms

## in CMSSW
from Validation.MuonHits.muonSimHitMatcherPSet import muonSimHitMatcherPSet
from Validation.MuonCSCDigis.muonCSCDigiPSet import muonCSCDigiPSet
from Validation.MuonCSCDigis.muonCSCStubPSet import muonCSCStubPSet
from Validation.MuonGEMDigis.muonGEMDigiPSet import muonGEMDigiPSet
from Validation.MuonGEMRecHits.muonGEMRecHitPSet import gemRecHit

CMSSWPSets = cms.PSet(
    muonSimHitMatcherPSet,
    muonCSCDigiPSet,
    muonCSCStubPSet,
    muonGEMDigiPSet,
    gemRecHit = gemRecHit
)

## in GEMCode
from L1Trigger.GEMCSCNtuplizer.simTrackPSets.genParticlePSet import genParticlePSet
from L1Trigger.GEMCSCNtuplizer.simTrackPSets.me0HitPSet import me0HitPSet
from L1Trigger.GEMCSCNtuplizer.simTrackPSets.muonRPCDigiPSet import muonRPCDigiPSet
from L1Trigger.GEMCSCNtuplizer.simTrackPSets.muonDTDigisPSet import muonDTDigisPSet
from L1Trigger.GEMCSCNtuplizer.simTrackPSets.muonDTStubPSet import muonDTStubPSet
from L1Trigger.GEMCSCNtuplizer.simTrackPSets.l1MuonPSet import l1MuonPSet
from L1Trigger.GEMCSCNtuplizer.simTrackPSets.l1TrackPSet import l1TrackPSet
from L1Trigger.GEMCSCNtuplizer.simTrackPSets.rpcRecHitPSet import rpcRecHitPSet
from L1Trigger.GEMCSCNtuplizer.simTrackPSets.cscRecHitPSet import cscRecHitPSet
from L1Trigger.GEMCSCNtuplizer.simTrackPSets.dtRecHitPSet import dtRecHitPSet
from L1Trigger.GEMCSCNtuplizer.simTrackPSets.recoTrackPSet import recoTrackPSet
from L1Trigger.GEMCSCNtuplizer.simTrackPSets.cclutPSet import cclutPSet
from L1Trigger.GEMCSCNtuplizer.simTrackPSets.showerPSet import showerPSet

GEMCodePSet = cms.PSet(
    genParticlePSet,
    me0HitPSet,
    muonRPCDigiPSet,
    muonDTDigisPSet,
    muonDTStubPSet,
    l1MuonPSet,
    l1TrackPSet,
    cscRecHitPSet,
    rpcRecHitPSet,
    dtRecHitPSet,
    recoTrackPSet,
    cclutPSet,
    showerPSet
)

## combine into single pset
simTrackPSet = cms.PSet(
    CMSSWPSets,
    GEMCodePSet,
)

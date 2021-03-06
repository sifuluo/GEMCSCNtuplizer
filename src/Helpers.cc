#include "L1Trigger/GEMCSCNtuplizer/interface/Helpers.h"

int gem::chamber(const DetId& id) {
  if (id.det() != DetId::Detector::Muon)
    return -99;
  int chamberN = 0;
  switch (id.subdetId()) {
    case MuonSubdetId::GEM:
      chamberN = GEMDetId(id).chamber();
      break;
    case MuonSubdetId::RPC:
      // works only for endcap!!
      chamberN = RPCDetId(id).sector();
      break;
    case MuonSubdetId::CSC:
      chamberN = CSCDetId(id).chamber();
      break;
    case MuonSubdetId::ME0:
      chamberN = ME0DetId(id).chamber();
      break;
    case MuonSubdetId::DT:
      chamberN = DTChamberId(id).sector();
      break;
  };
  return chamberN;
}

unsigned int gem::gemDetFromCSCDet(unsigned int id, int layer) {
  CSCDetId cscId(id);
  // returns the gem superr chamber for a given ME1/1 chamber(ME1/1a + ME1/1b)
  GEMDetId gemId(cscId.zendcap(), 1, cscId.station(), layer, cscId.chamber(), 0);
  return gemId.rawId();
}

std::pair<unsigned int, unsigned int> gem::gemDetsFromCSCDet(unsigned int id) {
  return std::make_pair(gemDetFromCSCDet(id, 1), gemDetFromCSCDet(id, 2));
}

float gem::cscHalfStripWidth(CSCDetId id) {
  // ME1a ME1b ME12 ME13 ME21 ME22 ME31 ME32 ME41 ME42
  int strips[10] = {48, 64, 80, 64, 80, 80, 80, 80, 80, 80};
  int degrees[10] = {10, 10, 10, 10, 20, 10, 20, 10, 20, 10};
  int index = id.iChamberType() - 1;
  float width = float(degrees[index]) * 3.14159265358979323846 / 180. / float(2 * strips[index]);
  return width;
}

// return MuonType for a particular DetId
int gem::toGEMType(int st, int ri) {
  if (st == 1) {
      return GEM_ME11;
  }
  else if (st == 2) {
      return GEM_ME21;
  }
  return GEM_ME0;
}

int gem::toRPCType(int re, int st, int ri) {
  // endcap
  if (std::abs(re) == 1) {
    if (st == 1) {
      if (ri == 2)
        return RPC_ME12;
      if (ri == 3)
        return RPC_ME13;
    } else if (st == 2) {
      if (ri == 2)
        return RPC_ME22;
      if (ri == 3)
        return RPC_ME23;
    } else if (st == 3) {
      if (ri == 1)
        return RPC_ME31;
      if (ri == 2)
        return RPC_ME32;
      if (ri == 3)
        return RPC_ME33;
    } else if (st == 4) {
      if (ri == 1)
        return RPC_ME41;
      if (ri == 2)
        return RPC_ME42;
      if (ri == 3)
        return RPC_ME43;
    }
  }
  // Barrel
  else {
    if (ri == -2) {
      if (st == 1)
        return RPC_MB21n;
      if (st == 2)
        return RPC_MB22n;
      if (st == 3)
        return RPC_MB23n;
      if (st == 4)
        return RPC_MB24n;
    } else if (ri == -1) {
      if (st == 1)
        return RPC_MB11n;
      if (st == 2)
        return RPC_MB12n;
      if (st == 3)
        return RPC_MB13n;
      if (st == 4)
        return RPC_MB14n;
    } else if (ri == 0) {
      if (st == 1)
        return RPC_MB01;
      if (st == 2)
        return RPC_MB02;
      if (st == 3)
        return RPC_MB03;
      if (st == 4)
        return RPC_MB04;
    } else if (ri == 1) {
      if (st == 1)
        return RPC_MB11p;
      if (st == 2)
        return RPC_MB12p;
      if (st == 3)
        return RPC_MB13p;
      if (st == 4)
        return RPC_MB14p;
    } else if (ri == 2) {
      if (st == 1)
        return RPC_MB21p;
      if (st == 2)
        return RPC_MB22p;
      if (st == 3)
        return RPC_MB23p;
      if (st == 4)
        return RPC_MB24p;
    }
  }
  return RPC_ME12;
}

int gem::toDTType(int wh, int st) {
  if (wh == -2) {
    if (st == 1)
      return DT_MB21n;
    if (st == 2)
      return DT_MB22n;
    if (st == 3)
      return DT_MB23n;
    if (st == 4)
      return DT_MB24n;
  }
  if (wh == -1) {
    if (st == 1)
      return DT_MB11n;
    if (st == 2)
      return DT_MB12n;
    if (st == 3)
      return DT_MB13n;
    if (st == 4)
      return DT_MB14n;
  }
  if (wh == 0) {
    if (st == 1)
      return DT_MB01;
    if (st == 2)
      return DT_MB02;
    if (st == 3)
      return DT_MB03;
    if (st == 4)
      return DT_MB04;
  }
  if (wh == 1) {
    if (st == 1)
      return DT_MB11p;
    if (st == 2)
      return DT_MB12p;
    if (st == 3)
      return DT_MB13p;
    if (st == 4)
      return DT_MB14p;
  }
  if (wh == 2) {
    if (st == 1)
      return DT_MB21p;
    if (st == 2)
      return DT_MB22p;
    if (st == 3)
      return DT_MB23p;
    if (st == 4)
      return DT_MB24p;
  }
  return DT_MB01;
}

int gem::toCSCType(int st, int ri) {
  if (st == 1) {
    if (ri == 0)
      return CSC_ME11;
    if (ri == 1)
      return CSC_ME1b;
    if (ri == 2)
      return CSC_ME12;
    if (ri == 3)
      return CSC_ME13;
    if (ri == 4)
      return CSC_ME1a;
  }
  else if (st == 2) {
    if (ri == 1)
      return CSC_ME21;
    if (ri == 2)
      return CSC_ME22;
  }
  else if (st == 3) {
    if (ri == 1)
      return CSC_ME31;
    if (ri == 2)
      return CSC_ME32;
  }
  else {
    if (ri == 1)
      return CSC_ME41;
    if (ri == 2)
      return CSC_ME42;
  }
  return CSC_ME11;
}

bool gem::PtOrder(const reco::GenParticle* p1, const reco::GenParticle* p2) { return (p1->pt() > p2->pt()); }

int gem::detIdToMEStation(int st, int ri)
{
  const auto& p(std::make_pair(st, ri));
  return std::find(cscStationsCo_.begin(), cscStationsCo_.end(), p) - cscStationsCo_.begin();
}

unsigned csc::get_csc_max_strip(int station, int ring) {
  int max_strip = 0;                // halfstrip
  if (station == 1 && ring == 4) {  // ME1/1a
    max_strip = 48;
  } else if (station == 1 && ring == 1) {  // ME1/1b
    // In the CSC local trigger
    // ME1/a is taken together with ME1/b
    max_strip = 64;
  } else if (station == 1 && ring == 2) {  // ME1/2
    max_strip = 80;
  } else if (station == 1 && ring == 3) {  // ME1/3
    max_strip = 64;
  } else if (station == 2 && ring == 1) {  // ME2/1
    max_strip = 80;
  } else if (station >= 3 && ring == 1) {  // ME3/1, ME4/1
    max_strip = 80;
  } else if (station >= 2 && ring == 2) {  // ME2/2, ME3/2, ME4/2
    max_strip = 80;
  }
  return max_strip;
}

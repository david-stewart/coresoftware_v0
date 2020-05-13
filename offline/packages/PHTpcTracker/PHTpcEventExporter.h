/*!
 *  \file       PHTpcEventExporter.h
 *  \brief      
 *  \author     Dmitry Arkhipkin <arkhipkin@bnl.gov>
 */

#ifndef PHTPCEVENTEXPORTER_H_
#define PHTPCEVENTEXPORTER_H_

#include <trackbase/TrkrClusterContainer.h>
#include "Track.h"
#include "externals/kdfinder.hpp"

/// \class PHTpcEventExporter
///
/// \brief
///
class PHTpcEventExporter
{
 public:
  PHTpcEventExporter();
  virtual ~PHTpcEventExporter() {}

  void exportEvent(TrkrClusterContainer* cluster_map, std::vector<kdfinder::TrackCandidate<double>*> candidates,
                   double B, const std::string& filename);

  void exportEvent(TrkrClusterContainer* cluster_map, std::vector<PHGenFit2::Track*> gtracks,
                   double B, const std::string& filename);

  void exportEvent(std::vector<PHGenFit2::Track*> gtracks, double B, const std::string& filename);

 protected:
 private:
};

#endif /* PHTPCEVENTEXPORTER_H_ */
/*!
 *  \file       PHTpcVertexFinder.h
 *  \brief      
 *  \author     Dmitry Arkhipkin <arkhipkin@gmail.com>
 */

#ifndef PHTPCVERTEXFINDER_H_
#define PHTPCVERTEXFINDER_H_

#include <GenFit/GFRaveTrackParameters.h>
#include <GenFit/GFRaveVertex.h>
#include <GenFit/GFRaveVertexFactory.h>
#include <phfield/PHField.h>
#include <vector>
#include "Track.h"

/// \class PHTpcVertexFinder
///
/// \brief
///
class PHTpcVertexFinder
{
 public:
  PHTpcVertexFinder();
  ~PHTpcVertexFinder();

  std::vector<genfit::GFRaveVertex*> findVertices(std::vector<PHGenFit2::Track*>& gtracks);

 protected:
  genfit::GFRaveVertexFactory* _vertex_finder;

 private:
};

#endif /* PHTPCVERTEXFINDER_H_ */
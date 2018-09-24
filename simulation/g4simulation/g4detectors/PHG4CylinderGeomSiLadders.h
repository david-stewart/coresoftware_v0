#ifndef G4DETECTORS_PHG4CYLINDERGEOMSILADDERS_H
#define G4DETECTORS_PHG4CYLINDERGEOMSILADDERS_H

#include "PHG4CylinderGeom.h"

#include <phool/phool.h>
#include <cmath>

class PHG4CylinderGeomSiLadders: public PHG4CylinderGeom
  {
  public:
    PHG4CylinderGeomSiLadders();
    PHG4CylinderGeomSiLadders(
      const int    layer,
      const double strip_x,
      const double strip_y,
      const double strip_z0,
      const double strip_z1,
      const int    nstrips_z_sensor0,
      const int    nstrips_z_sensor1,
      const int    nstrips_phi_cell,
      const int    nladders_layer,
      const double ladder_z0,
      const double ladder_z1,
      const double sensor_radius,
      const double strip_x_offset,
      const double offsetphi_,
      const double offsetrot_) :
        m_Layer(layer),
        m_NStripsPhiCell(nstrips_phi_cell),
        m_StripX(strip_x),
        m_StripY(strip_y),
        m_SensorRadius(sensor_radius),
        m_StripXOffset(strip_x_offset),
        offsetphi(offsetphi_),
	offsetrot(offsetrot_),
	radius(NAN)
    {
      // Type-A
      m_StripZ[0]          = strip_z0;
      m_LadderZ[0]         = ladder_z0;
      m_NStripsZSensor[0] = nstrips_z_sensor0;

      // Type-B
      m_StripZ[1]          = strip_z1;
      m_LadderZ[1]         = ladder_z1;
      m_NStripsZSensor[1] = nstrips_z_sensor1;

      dphi_ = 2.*M_PI/nladders_layer;
    }

    void identify(std::ostream& os = std::cout) const;
    void set_layer(const int i)
    {
      m_Layer = i;
    }

    int get_layer() const
      {
        return m_Layer;
      }

    double get_radius() const
      {
	return m_SensorRadius;
      }

    bool load_geometry();
    void find_segment_center(const int segment_z_bin, const int segment_phi_bin, double location[]);
    void find_strip_center(  const int segment_z_bin, const int segment_phi_bin, const int strip_column, const int strip_index, double location[]);
    void find_strip_index_values(const int segment_z_bin, const double ypos, const double zpos,  int &strip_y_index, int &strip_z_index);
    void find_strip_center_localcoords(const int segment_z_bin, const int strip_y_index, const int strip_z_index, double location[]);

    double get_thickness() const
      {
        return m_StripX;
      }

    double get_strip_y_spacing() const
      {
        return m_StripY;
      }

    double get_strip_z_spacing() const
      {
        return m_StripZ[0];
      }

    double get_strip_tilt() const
      {
        return 0.;
      }

    double get_strip_phi_tilt() const
      {
        return offsetrot;
      }

  protected:

    int m_Layer;
    int m_NStripsPhiCell;
    int m_NStripsZSensor[2];
    double m_StripX;
    double m_StripY;
    double m_SensorRadius;
    double m_StripXOffset;
    double offsetphi;
    double offsetrot;

    double m_StripZ[2];
    double m_LadderZ[2];
    double dphi_;

    double radius;

    ClassDef(PHG4CylinderGeomSiLadders,1)
  };

#endif

#ifndef PYFRCONTOURFILTER_H
#define PYFRCONTOURFILTER_H

#include <string>
#include <vector>

//State that the default backend for this code is CUDA
//not serial
// #define VTKM_DEVICE_ADAPTER VTKM_DEVICE_ADAPTER_CUDA
//Disable treading support in our array handle
//needed for nvcc to stop complaining.
#define BOOST_SP_DISABLE_THREADS

class PyFRData;
class PyFRContourData;

class PyFRContourFilter
{
public:
  PyFRContourFilter();
  virtual ~PyFRContourFilter();

  void operator ()(PyFRData*,PyFRContourData*) const;

  void AddContourValue(FPType value) { this->ContourValues.push_back(value); }
  void ClearContourValues()          { this->ContourValues.clear(); }

  void SetContourField(int i);
  void SetContourFieldToDensity()    { this->ContourField = "density"; }
  void SetContourFieldToPressure()   { this->ContourField = "pressure"; }
  void SetContourFieldToVelocity_u() { this->ContourField = "velocity_u"; }
  void SetContourFieldToVelocity_v() { this->ContourField = "velocity_v"; }
  void SetContourFieldToVelocity_w() { this->ContourField = "velocity_w"; }

protected:
  std::vector<FPType> ContourValues;
  std::string ContourField;
};
#endif
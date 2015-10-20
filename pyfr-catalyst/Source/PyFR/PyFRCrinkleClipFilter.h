#ifndef PYFRCRINKLECLIPFILTER_H
#define PYFRCRINKLECLIPFILTER_H

#define BOOST_SP_DISABLE_THREADS

class PyFRData;

class vtkSphere;
class vtkPlane;

class PyFRCrinkleClipFilter
{
public:
  PyFRCrinkleClipFilter() {}
  virtual ~PyFRCrinkleClipFilter() {}

  void operator ()(PyFRData* inputData,PyFRData* outputData,vtkSphere*) const;
  void operator ()(PyFRData* inputData,PyFRData* outputData,vtkPlane*) const;

};

#endif
#ifndef PLOTS_HPP
#define PLOTS_HPP

#include <string>
#include <vector>

//MathGL inclusions
#include <mgl/mgl.h>
#include <mgl/mgl_zb.h>

void TSPlot(double x[], double y[], int size, std::string name);

void RecurrencePlot(double data[], int size, std::string recurrence_name);


#endif

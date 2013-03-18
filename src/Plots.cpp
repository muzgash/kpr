#include "Plots.hpp"

void TSPlot(double x[], double y[], int size, std::string name)
{
	mglData number, weekends;
	number.Set(y,size);
	weekends.Set(x,size);
	mglGraphZB ts;
	ts.Alpha(false);
	ts.Light(true);
	ts.Transparent=false;
	ts.XRange(weekends,false,0);
	ts.YRange(number,false,0);
	ts.Title("","iC",8);;
	ts.Axis();
	ts.Plot(weekends,number,"k-");
	ts.WritePNG(name.c_str());

}

void RecurrencePlot(double data[], int size, std::string recurrence_name)
{
    std::vector<double> vectorx,vectory;
	double *recx,*recy;

	for( int j=100; j<size; j++ ){
	for( int k=100; k<size; k++ ){
	if(data[j]==data[k]){
	vectorx.push_back((double)j);
	vectory.push_back((double)k);
	}}}
	int vec_size=vectorx.size();
	recx = new double[vec_size];
	recx=vectorx.data();
	recy = new double[vec_size];
	recy=vectory.data();

	mglData x, y;
	x.Set(recx,vec_size);
	y.Set(recy,vec_size);
	mglGraphZB rp;
	rp.Alpha(false);
	rp.Light(true);
	rp.Transparent=false;
	rp.XRange(x,false,0);
	rp.YRange(y,false,0);
	rp.Title("","iC",8);;
	rp.Axis();
	rp.SetMarkSize(0.005);
	rp.Plot(x,y,"G #o");
	rp.WritePNG(recurrence_name.c_str());

	vectorx.clear();
	vectory.clear();

}

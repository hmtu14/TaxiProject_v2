#include "Trajectory.h"



Trajectory::Trajectory()
{
}

vector<vector<int>> Trajectory::toVec(DateTime t, int timestamp, Coord &top, Coord &btm)
{
	vector<vector<int>> res;
	double lat_thres = (btm.Latitude - top.Latitude) / gSize;
	double lng_thres = (btm.Longitude - top.Longitude) / gSize;
	for (int i = 0; i < t.getCumMinute(); i + timestamp) {
		for (auto gps : lstGPS) {
			res[i][gps.coord.Longitude / lng_thres*gSize + gps.coord.Latitude / lat_thres]++;
		}
	}
	return res;
}


//d(A, B) = SUM(ABS(A[i][j] - B[i][j]) 
double Trajectory::vecDistance(DateTime t, int timestamp, Coord top, Coord btm,Trajectory &nTracjec)
{
	double res = 0;
	vector<vector<int>> mVec = this->toVec(t, timestamp, top, btm);
	vector<vector<int>> nVec = nTracjec.toVec(t, timestamp, top, btm);
	for (int i = 0; i < mVec.size(); i++) {
		for (int j = 0; j < mVec[0].size(); j++) {
			res += sqrt(abs(mVec[i][j] - nVec[i][j]));
		}
	}
	return res;
}

vector<Trajectory> Trajectory::findSimilar(DateTime t, int timestamp, Coord top, Coord btm,const vector<Trajectory> &lstTracjectory)
{
	vector<Trajectory> res = lstTracjectory;
	sort(res.begin(), res.end(), cmpTrajectory(*this, t, timestamp, top, btm)); 
	return res;
}


Trajectory::~Trajectory()
{
}

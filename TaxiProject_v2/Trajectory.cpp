#include "Trajectory.h"



Trajectory::Trajectory()
{
}

vector<vector<int>> Trajectory::toVec(DateTime t, int timestamp, Coord top, Coord btm)
{
	vector<vector<int>> res;
	double lat_thres = (btm.lat - top.lat) / gSize;
	double lng_thres = (btm.lng - top.lng) / gSize;
	for (int i = 0; i < t.getCumMinute(); i + timestamp) {
		for (auto taxi : lstTaxi) {
			res[i][taxi.getCoord().lng / lng_thres*gSize + taxi.getCoord().lat / lat_thres]++;
		}
	}	
	return vector<vector<int>>();
}

Trajectory::~Trajectory()
{
}

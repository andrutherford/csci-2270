//Andrew Rutherford
//CSCI 2270

#include "graph.h"
using namespace std;

// default constructor at work here; pretty cute!
graph::graph()
{
	vector<vertex> vertices;
	map<vertex*, vector<vertex*>>edges;
}	

// destructor is easy, we just clear our vertex vector and our edge map
graph::~graph()
{
	vertices.clear();
	edges.clear();
}	

// add a vertex to the graph by adding it to the vector
void graph::add_vertex(const vertex& v) 
{
	vertices.push_back(v);
}

// add an edge to the graph as long as it's under the distance limit
void graph::add_edge(vertex* v, vertex* u, double limit)
{
	if ( great_circle_distance(*v, *u) <= limit)
	{
		//If the distance from u to v is within limit, do this:
		edges[v].push_back(u);
	}
}

// compute distance from one lat/long to another as the crow flies
double graph::great_circle_distance(const vertex& v, const vertex& u) const
{
	double PI = 3.1415926535897932;
	double lat1, lat2, long1, long2, dist;

	lat1 = ((double) v.get_latitude_degrees()) + (((double) v.get_latitude_minutes()) / 60.0);
	lat1 *= PI/180.0;
	long1 = ((double) v.get_longitude_degrees()) + (((double) v.get_longitude_minutes()) / 60.0);
	long1 *= PI/180.0;
	lat2 = ((double) u.get_latitude_degrees()) + (((double) u.get_latitude_minutes()) / 60.0);
	lat2 *= PI/180.0;
	long2 = ((double) u.get_longitude_degrees()) + (((double) u.get_longitude_minutes()) / 60.0);
	long2 *= PI/180.0;

	// from http://www.meridianworlddata.com/Distance-Calculation.asp
	// result in km
	dist = 6378.7 * acos((sin(lat1) * sin(lat2)) + (cos(lat1) * cos(lat2) * cos(long2 - long1)));

	return dist;
}

// read in 120 cities and their latitude/longitude
// cities within limit km of each other are connected by edges
void init_graph_from_file(graph& g, const string& filename, double limit)
{
	string line;
	string city_name;
	int lat1, lat2, long1, long2;
	ifstream file_to_read;
	char compass_dir;

	// open the data file of cities
	open_for_read(file_to_read, filename);
	
// while there is still stuff to read in the file
	//read in each line of the file, using getline (http://www.cplusplus.com/reference/string/string/getline/)
	//get the city name, lat degrees, lat minutes, long degrees, long seconds the string find and substr functions will be helpful
	//create a vertex from these using the vertex constructor
	//add this vertex to the vertices vector
	
	while(is_more_stuff_there(file_to_read))
	{
		getline(file_to_read,city_name,':');
		file_to_read>>lat1>>lat2>>compass_dir;
		
		if(compass_dir=='E')
		{
			lat1 = -lat1;
			lat2 = -lat2;
		}
		
		file_to_read>>long1>>long2>>compass_dir;
		
		if(compass_dir=='S')
		{
			long1 = -long1;
			long2 = -long2;
		}
		
		/* ORIGINALLY CODED THIS WAY - REPLACED
		
		getline(file_to_read,line,':');
		city_name = line;
		cout << city_name << endl;
		
		getline(file_to_read,line,' ');
		getline(file_to_read,line,' ');
		lat1 = atoi(line.c_str());	
		getline(file_to_read,line,' ');
		lat2 = atoi(line.c_str());
				
		getline(file_to_read,line,' ');
		if(line == "S")
		{
			lat1 = -lat1;
			lat2 = -lat2;
		}
		
		cout << "LATITUDE " << lat1 << " DEGREES " << lat2 << " MINUTES " << endl;
		
		getline(file_to_read,line,' ');
		long1 = atoi(line.c_str());
		getline(file_to_read,line,' ');
		long2 = atoi(line.c_str());
		
		getline(file_to_read,line,' ');
		if(line == "W")
		{
			long1 = -long1;
			long2 = -long2;
		}
		cout << "LONGITUDE " << long1 << " DEGREES " << long2 << " MINUTES " << endl << endl;
	*/
}
	vertex city(city_name, lat1, lat2, long1, long2); // constructor call 
	g.add_vertex(city); // this code just puts this vertex at the end of our vertices array
	
	// now we are done with our file
	file_to_read.close();

	//Nested loop
	for(unsigned int i = 0; i<g.vertices.size()-1;++i)
	{
		for(unsigned int j=0; j<g.vertices.size()-1;++j)
		{
			if (i != j)
			{
				g.add_edge(&g.vertices[i],&g.vertices[j],limit);
			}
		}
	}
}

// function defined by Michael Main for input data
void open_for_read(ifstream& f, string filename)
{
	f.open(filename);
	if (f.fail())
	{
		cerr << "Could not open input file." << endl;
		exit(0);
	}
}

// function defined by Michael Main for input data
bool is_more_stuff_there(ifstream& f)
{
		return (f && (f.peek() != EOF));
}





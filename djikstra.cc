#include <iostream>
#include <limits>  // for numeric_limits<int>::max
#include <utility> //for pair
#include <vector>
#include <stack>
using namespace std;

/* TODO:
 * create shell function djikstra to call shortestPath function
 *  shortestPath needs to "return" predecessor array
 *  predecessor array needs to be able to hold coordinate pairs of entire matrix
 * change names of some variables
 * change parameters to shortestPath
 * change condition mentioned in shortestPath comments
 * determine matrix dimensions using matrix (shortestPath or djikstra?)
 * update convertMatrix to not assume a square matrix is being used
 */

void shortestPath(vector<vector<int>> distances, vector<int> preds, int vertex,
                  int size);

void convertMatrix(vector<int> &mazeVect, vector<vector<int>> &distances);

void dijkstra(vector<int> mazeVector, pair<int, int> coordinates);

int main() {
  // test main for algorithm development

  vector<int> maze = {1, 0, 1, 1, 1, 1, 0, 1, 0};
  pair<int, int> coord(0, 0);
  dijkstra(maze, coord);

  cout << "HELLO WORLD" << endl;
  return 0;
}

void dijkstra(vector<int> mazeVector, pair<int, int> coordinates) {
  /* Strategy
   * find dimensions of the mazeVector
   *  use size of outside vector for x dimension
   *  use size of nested vector for y dimension
   * create empty array for predecessors
   * call shortestPath with given parameters and new pair and matrix
   *
   * sort through the predecessors array to find the path using coordinates
   *  use a stack to push the pairs
   *  pop the pairs into an array which should be returned eventually (won't be
   *  for now)
   */

  // pair<int, int> dimensions(mazeVector.size(), mazeVector[0].size());
  int width = 3;
  int height = 3;
  int size = width * height;
  vector<int> predecessors(size);

  // create x*y by x*y size matrix, full of zeroes
  vector<vector<int>> distances(size, vector<int>(size, 0));
  convertMatrix(mazeVector, distances);

  // testing
  cout << endl;
  for (int i = 0; i < distances.size(); i++) {
    for (int j = 0; j < distances.size(); j++) {
      cout << distances[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  // not trusting compiler init
  for (int i = 0; i < size; i++) {
    predecessors[i] = 0;
  }

  // testing
  for (int i = 0; i < size; i++) {
    cout << predecessors[i] << " ";
  }
  cout << endl;

  cout << "entering" << endl;

  int vertex = 0;
  shortestPath(distances, predecessors, vertex, size);

  cout << "exiting" << endl;

  int pred = size - 1;
  stack<int> path;
  while (pred != 0){
    path.push(mazeVector[pred]);
  }

  while(path.size() != 0){
    int c = path.top();
    cout << c << " ";
    path.pop();
  }

}

void shortestPath(vector<vector<int>> distances, vector<int> preds, int vertex,
                  int size) {

  int dists[size];
  for (int i = 0; i < size; i++) {
    dists[i] = distances[vertex][i];
  }

  bool *distFound;
  distFound = new bool[size];

  for (int i = 0; i < size; i++) {
    distFound[i] = false;
  }

  distFound[vertex] = true;
  dists[vertex] = 0;
  preds[vertex] = 0;

  for (int i = 0; i < size; i++) {
    int smallestDist = numeric_limits<int>::max();
    int currentSmallest;

    for (int j = 0; j < size; j++) {
      if (!distFound[j]) {
        if (dists[j] < smallestDist && dists[j] > 0) {
          currentSmallest = j;
          smallestDist = dists[currentSmallest];
        }
      }
    }

    distFound[currentSmallest] = true;

    for (int j = 0; j < size; j++) {
      if (!distFound[j]) {
        if ((smallestDist + distances[currentSmallest][j] < dists[j] &&
             distances[currentSmallest][j] > 0) ||
            (dists[j] == 0 && distances[currentSmallest][j] > 0)) {
          dists[j] = smallestDist + distances[currentSmallest][j];
          preds[j] = currentSmallest;
        }
      }
    }
  }
}

void convertMatrix(vector<int> &mazeVect, vector<vector<int>> &distances) {
  // temporary 1d array
  vector<int> temp(81);

  // go through 1d mazeVect and create adjacency matrix in temp
  for (int x = 0; x < 9; x++) {
    int i;
    for (int y = 0; y < 9; y++) {
      if (y >= 6) {
        i = 2;
      } else if (y >= 3 && y < 6) {
        i = 1;
      } else {
        i = 0;
      }

      int j = y % 3;
      int loc = y + x * 9;
      int tempLoc = j + i * 3;

      if (x == y) {
        // can't have a path to self
        temp[loc] = 0;
      } else {

        if (mazeVect[tempLoc] == 1) {
          if ((x - 3 == tempLoc) || (x + 3 == tempLoc) ||
              (x - 1 == tempLoc && tempLoc % 3 != 2) ||
              (x + 1 == tempLoc && tempLoc % 3 != 0)) {
            // two nodes are next to each other and have a path to each other
            temp[loc] = 1;
          }
        } else {
          // edge goes from path to a wall (doesn't work when going from wall to
          // path)
          temp[loc] = -1;
        }
      }

    } // end for y < 9
  }   // end for x < 9

  // put temp into two dimensional distances
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int loc = j + i * 9;
      distances[i][j] = temp[loc];
    }
  }
} // end function convertMatrix

// void shortestPath(vector<vector<int>> distances, vector<pair<int, int>>
// preds;
//                   int vertex, int numCities) {
//   /* Things that need to change
//    * numCities name will change and will be defined locally
//    *   will use the dimension of one vector/row to determine
//    * a parameter specifying the vertex will probably replace numCities
//    * mazeVector needs to be converted to a proper distances function
//    * condition in the first inner for-loop needs to be changed
//    * maybe change names of a few other variable to be more context-relevant\
//    * predecessors needs to use coordinates
//    */

//   /// arrays for the weights of each path and the predecessors of each node
//   /// weights will always be 1 in this version
//   int dists[numCities];

//   /// fill dists with weights from vertex to any other node
//   for (int i = 0; i < numCities; i++) {
//     dists[i] = distances[vertex][i];
//   }

//   /// array used to know if the distance between any node and the vertex has
//   /// been determined
//   bool *distFound;
//   distFound = new bool[numCities];

//   for (int i = 0; i < numCities; i++) {
//     distFound[i] = false;
//   }

//   // at start, only the vertex info is known
//   distFound[vertex] = true;
//   dists[vertex] = 0;
//   preds[vertex].first = 0;
//   preds[vertex].second = 0;

//   /// the heart of the algorithm
//   for (int i = 0; i < numCities; i++) {
//     // https://stackoverflow.com/questions/23278930/what-is-dbl-max-in-c
//     int smallestDist = numeric_limits<int>::max();
//     int currentSmallest;

//     /// find the smallest distance
//     for (int j = 0; j < numCities; j++) {
//       if (!distFound[j]) {
//         // should probably make this condition > 0, not != 0
//         if (dists[j] < smallestDist && dists[j] != 0) {
//           currentSmallest = j;
//           smallestDist = dists[currentSmallest];
//         }
//       }
//     }

//     distFound[currentSmallest] = true;

//     /// update neighbors
//     for (int j = 0; j < numCities; j++) {
//       if (!distFound[j]) {
//         // Make sure neighbors are updated, even if they have a distance of 0
//         if ((smallestDist + distances[currentSmallest][j] < dists[j] &&
//              distances[currentSmallest][j] != 0) ||
//             (dists[j] == 0 && distances[currentSmallest][j] != 0)) {
//           dists[j] = smallestDist + distances[currentSmallest][j];
//           preds[j] = currentSmallest;
//         }
//       }
//     }
//   }
// } // end function shortestPath
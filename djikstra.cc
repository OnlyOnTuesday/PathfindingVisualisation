#include <iostream>
#include <limits>
#include <vector>
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

void shortestPath(vector<vector<int>> distances, int vertex, int numCities);

void convertMatrix(vector<vector<int>> &mazeVect,
                   vector<vector<int>> &distances);

int main() {
  // test main for algorithm development

  vector<vector<int>> test = {{1, 0, 0}, {1, 1, 1}, {1, 0, 1}};
  vector<vector<int>> result(3, vector<int>(3, 0));

  for (int i = 0; i < test.size(); i++) {
    for (int j = 0; j < test.size(); j++) {
      cout << test.at(i).at(j) << " ";
    }
    cout << endl;
  }
  cout << endl;

  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result.size(); j++) {
      cout << result.at(i).at(j) << " ";
    }
    cout << endl;
  }
  cout << endl;

  convertMatrix(test, result);

  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result.size(); j++) {
      cout << result.at(i).at(j) << " ";
    }
    cout << endl;
  }
  cout << endl;

  cout << "HELLO WORLD" << endl;
  return 0;
}

void shortestPath(vector<vector<int>> mazeVector, int vertex, int numCities) {
  /* Things that need to change
   * numCities name will change and will be defined locally
   *   will use the dimension of one vector/row to determine
   * a parameter specifying the vertex will probably replace numCities
   * mazeVector needs to be converted to a proper distances function
   * condition in the first inner for-loop needs to be changed
   * maybe change names of a few other variable to be more context-relevant
   */

  /// convert the maze matrix to a distance matrix
  vector<vector<int>> distances(numCities, vector<int>(numCities));
  convertMatrix(mazeVector, distances);

  /// arrays for the weights of each path and the predecessors of each node
  /// weights will always be 1 in this version
  int dists[numCities];
  int preds[numCities];

  /// fill dists with weights from vertex to any other node
  for (int i = 0; i < numCities; i++) {
    dists[i] = distances[vertex][i];
  }

  /// array used to know if the distance between any node and the vertex has
  /// been determined
  bool *distFound;
  distFound = new bool[numCities];

  for (int i = 0; i < numCities; i++) {
    distFound[i] = false;
  }

  // at start, only the vertex info is known
  distFound[vertex] = true;
  dists[vertex] = 0;
  preds[vertex] = 0;

  /// the heart of the algorithm
  for (int i = 0; i < numCities; i++) {
    // https://stackoverflow.com/questions/23278930/what-is-dbl-max-in-c
    int smallestDist = numeric_limits<int>::max();
    int currentSmallest;

    /// find the smallest distance
    for (int j = 0; j < numCities; j++) {
      if (!distFound[j]) {
        // should probably make this condition > 0, not != 0
        if (dists[j] < smallestDist && dists[j] != 0) {
          currentSmallest = j;
          smallestDist = dists[currentSmallest];
        }
      }
    }

    distFound[currentSmallest] = true;

    /// update neighbors
    for (int j = 0; j < numCities; j++) {
      if (!distFound[j]) {
        // Make sure neighbors are updated, even if they have a distance of 0
        if ((smallestDist + distances[currentSmallest][j] < dists[j] &&
             distances[currentSmallest][j] != 0) ||
            (dists[j] == 0 && distances[currentSmallest][j] != 0)) {
          dists[j] = smallestDist + distances[currentSmallest][j];
          preds[j] = currentSmallest;
        }
      }
    }
  }
} // end function shortestPath

void convertMatrix(vector<vector<int>> &mazeVect,
                   vector<vector<int>> &distances) {
  /* Strategy
   * if the value of mazeVect is 0, make it -1;
   * if the value of mazeVect is 1, make it 0
   *   only keep it 1 if it's an immediate neighbor of the vertex
   */

  /// iterate through nested vectors and make proper conversions
  for (int i = 0; i < mazeVect.size(); i++) {
    for (int j = 0; j < mazeVect.size(); j++) {
      switch (mazeVect[i][j]) {
      case 0:
        distances[i][j] = -1;
        break;
      case 1:
        // assume that vertex is (0,0) for now
        if ((i == 0 && j == 1) || (i == 1 && j == 0) || (i == 0 && j == 0)) {
          distances[i][j] = 1;
        } else {
          distances[i][j] = 0;
        }
        break;
      } // end switch statement
    }   // end for j < mazeVect.size() loop
  }     // end for i < mazeVect.size() loop
} // end of function convertMatrix()
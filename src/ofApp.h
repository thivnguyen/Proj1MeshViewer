//
//  ofApp.h
//  Proj1MeshViewer
//
//  Last edited by Thi Nguyen on 9/17/20.
//

#pragma once

#include "ofMain.h"
#include "Mesh.h"
using namespace glm;
class Mesh;
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        void readFromOBJFile(string path);
        void drawAxis();
    
private:
        ofEasyCam cam;
        Mesh createdMesh;
};

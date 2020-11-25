#include <iostream>
#include <vector> 
#include <string>
#include <stdlib.h>
//#include <iomanip>
#include<sstream>
using namespace std; 

struct Node{
	float coef;
	int power;
};
vector<Node> poly1;
vector<Node> poly2;
vector<Node> result;

//function1
vector<Node> sort(vector<Node> poly, string s){
	int n = 0;
	int i = 0;
	string sub = "";
	string coefstring = "";
	Node node;
	while(n<s.length()){
		if(s[n] != '+' && s[n] != '-'){			//若不是加減符號 
			sub += s[n];
			n++;
		}else{				//若是加減符號則進行分類 
			while(i<sub.length()){		//例如:sub = 5x^3 進行前後分割 
				if(sub[i] != 'x'){		
					coefstring += sub[i];
					i++;
				}else{
					i += 2;
					if(coefstring == ""){
						node.coef = 1.0;
					}else{
						node.coef = atof(coefstring.data());
					}
					node.power = atof(sub.substr(i).data());
					poly.push_back(node);
					sub = "";
					coefstring = "";
					break;
				}
			}
			
			if(s[n] == '-'){			//嚙緘嚙瘦嚙磊嚙諉數字嚙瞌嚙緣嚙複開嚙磐嚙踝蕭嚙稼- 
				sub += "-";
			}
			i = 0;
			n++;
		}
	}
	
	while(i<sub.length()){
		if(sub[i] != 'x'){
			coefstring += sub[i];
			i++;
		}else{
			i += 2;
			if(coefstring == ""){
				node.coef = 1.0;
			}else{
				node.coef = atof(coefstring.data());
			}
			node.power = atof(sub.substr(i).data());
			poly.push_back(node);
			sub = "";
			break;
		}
	}

	if(sub.length() != 0){
		node.coef = atof(sub.data());
		node.power = 0;
		poly.push_back(node);
	}

	return poly;
}

//function2
string tostring(float f){
	stringstream ss;
	ss<<f;
	string s(ss.str());
	return s;
}

int main(){
	string polystr1 = "5.1x^5+3x^3+1";
	string polystr2 = "4x^5+2x^2+x^1";
	// cin >> polystr1;
	// cin >> polystr2;
	poly1 = sort(poly1, polystr1);
	poly2 = sort(poly2, polystr2);

	//counting
	Node element1;
	Node element2;
	int n1=0;
	int n2=0;
	Node temp;
	while(poly1.size() > n1 && poly2.size() > n2){
		element1 = poly1[n1];
		element2 = poly2[n2];
		if(element1.power > element2.power){
			result.push_back(element1);
			n1++;
		}else if(element1.power < element2.power){
			result.push_back(element2);
			n2++;
		}else{
			temp.coef = element1.coef + element2.coef;
			temp.power = element1.power;
			result.push_back(temp);
			n1++;
			n2++;
		}
	}

	while(poly1.size() > n1){
		result.push_back(element1);
		n1++;
	}
	while(poly2.size() > n2){
		result.push_back(element2);
		n2++;
	}

	//printout
	string output;
	output += tostring(result[0].coef);
	output += "x^";
	output += tostring(result[0].power);
	for(int j=1; j < result.size(); j++){
		if(result[j].coef > 0){
			output += "+";
		}
		output += tostring(result[j].coef);
		if(result[j].power != 0){
			output += "x^";
			output += tostring(result[j].power);
		}
	}

	// int i=0;
	// while(i<result.size()){
	// 	cout << result[i].coef << " " << result[i].power << endl;
	// 	i++;
	// }

	cout << output << endl;

	return 0;
}

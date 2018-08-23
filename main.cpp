/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/*
 * File:   main.cpp
 * Author: Leo, Diego, Jesús
 *
 * Created on August 20, 2018, 5:07 PM
 */
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <list>
using namespace std;
string cambio(string sigla){
         if(sigla== "SP")  {sigla="SO";}
    else if(sigla== "SO")  {sigla="SP";}
    else if(sigla== "LH")  {sigla="HE";}
    else if(sigla== "HE")  {sigla="LH";}
    else if(sigla== "BA")  {sigla="BQ";}
    else if(sigla== "BQ")  {sigla="BA";}
    else if(sigla== "LE")  {sigla="LEN";}
    else if(sigla== "LEN") {sigla="LE";}
    else if(sigla== "TB")  {sigla="TOB";}
    else if(sigla== "TOB") {sigla="TB";}
    else if(sigla== "LC")  {sigla="LCI";}
    else if(sigla== "LCI") {sigla="LC";}
    else if(sigla== "AN")  {sigla="NA";}
    else if(sigla== "NA")  {sigla="AN";}
    else if(sigla== "FR")  {sigla="FRA";}
    else if(sigla== "FRA") {sigla="FR";}
    else if(sigla== "VMA") {sigla="VIM";}
    else if(sigla== "VIM") {sigla="VMA";}
    else if(sigla== "VVA") {sigla="VV";}
    else if(sigla== "VV")  {sigla="VVA";}
    else if(sigla== "NU")  {sigla="NUO";}
    else if(sigla== "NUO") {sigla="NU";}
  return sigla;}
string removeSpaces(string input)
{
  for (int i = input.length()-1; i >= 0; --i) {
   if(input[i] == ' ')
      input.erase(i, 1);
}
  return input;
}

std::string buscarcombinaciones(std::string LO, std::string LD) {
  ifstream combi;
  combi.open("combinaciones.txt");
  std::string sigla,linea,line,bandera;
  while (!combi.eof()){
      getline(combi,sigla,' ');//SP
      getline(combi,linea,' ');//1
      getline(combi,line,'\n');//5
      if(linea==removeSpaces(LO) || linea==removeSpaces(LD)){
          std::cout<< sigla<< line << linea << '\n';
  }else{getline(combi,line,'\n');}
}
combi.close();
return sigla;
}

void doit(std::string O, std::string D, bool flag){
  int i=0;
  std::string reverse[40];
  ifstream myfile;
  myfile.open("metro.txt");
  myfile.clear();
  myfile.seekg(0, ios::beg);
  string line,linea, lineao, linead, ori, des;
  while(!myfile.eof()){
    getline(myfile,line,' ');
//    std::cout << line << '\n';
    if (line == O){
      if (flag==true) {
        do {
          getline(myfile,line,'\n');
          std::cout << line << ' ';
          getline(myfile,line,' ');
        } while(line!=D);
        getline(myfile,line,'\n');
        std::cout << line << ' ';
      } else {
        do {
          getline(myfile,line,'\n');
          reverse[i]=line;
          i++;
          getline(myfile,line,' ');
        } while(line!=D);
        getline(myfile,line,'\n');
        reverse[i]=line;
        i++;
      }
    } else {
      getline(myfile,line,'\n');
    }
  }
  while (i!=-1) {
    std::cout << reverse [i]<< ' ';
    i--;
  }
 myfile.clear();
 myfile.seekg(0, myfile.beg);
 myfile.close();
}

void r(std::string O, std::string D){
int i=0;
ifstream myfile,combi;
myfile.open("metro.txt");
myfile.clear();
myfile.seekg(0, myfile.beg);
string line,linea, lineao, linead, ori, des, flag,myline,sigla,change,x;
bool found = false;
while(!myfile.eof())
{getline(myfile,line,' ');
if(line.find("Línea") != string::npos ) //HERE!
{
getline(myfile,line,'\n');
myline=line;
//cout << line << endl;
// getline(myfile,line,' ');
 }
else if(line==D){
  i++;
            flag="N";
          getline(myfile,line,'\n');
          //cout <<line << endl;//cout <<linea << endl;
          linead=myline;
          des=line;
    //      getline(myfile,line,' ');
    }
else if(line==O){
        flag="R";
          getline(myfile,line,'\n');
          //cout <<line << endl;//cout <<linea << endl;
          lineao=myline;
          ori=line;
          i++;
  //        getline(myfile,line,' ');
         /* getline(myfile,line,' ');
          do{
      // cout <<"Sigla: "<<line << endl;
       getline(myfile,line,'\n');
        cout <<line << endl;
        getline(myfile,line,' ');
          }while(line!=D);
    getline(myfile,line,'\n');
        cout <<line << endl;*/

  }
  else{getline(myfile,line,'\n');i++;}

}
//std::cout << i<< '\n';
//cout <<ori << endl;
//cout <<lineao << endl;
//cout <<des << endl;
//cout <<linead << endl;
myfile.clear();
myfile.seekg(0, myfile.beg);
myfile.close();
if(lineao==linead){
  if(flag=="N"){
    doit(O,D,true);
  }else{
    doit(D,O,false);}
  }
else{
  combi.open("combinaciones.txt");
  combi.clear();
  combi.seekg(0, combi.beg);
  while (!combi.eof()){
    getline(combi,sigla,' ');//SP
    getline(combi,linea,' ');//1
    getline(combi,line,'\n');//5
    if(linea==removeSpaces(lineao)){
      if(line==removeSpaces(linead)){
               //cout<<sigla<<" "<<x<<" "<<linea<<" "<<line;
               //r(O,sigla);
        change=cambio(sigla);
        r(O,sigla);
        r(change,D);
            //   r(sigla,D);
       //      doit(change,D,F);
        break;exit(0);}
        }
        else{}
        //buscarcombinaciones(removeSpaces(lineao),removeSpaces(linead));
    }
    combi.clear();
    combi.seekg(0, combi.beg);
    combi.close();
//    r(O,sigla);
//    r(change,D);
  //  std::cout << lineao<<linead << '\n';
  //  std::cout << ori<<des << '\n';
  //searchit(O,D,lineao,linead,flag);
  //doit(gg,D,flag);
}
}
int main(int argc, char** argv) {

    string Argumento = argv[1];
    if(Argumento=="-v"){
    cout<<"Leonardo Aillapan Cuellar"<<endl;
    cout<<"Diego Pino Contreras"<<endl;
    cout<<"Jesús Zagal Velozo"<<endl;
    }else if(Argumento=="-f"){
      string Destino = argv[3];
    string Origen = argv[2];
     //cout<<"Ruta"<<endl<<Origen<<endl<<Destino<<endl;
     if (Origen == Destino) {
       ifstream metro;
       std::string line;
       metro.open("metro.txt");
       metro.clear();
       metro.seekg(0, metro.beg);
       while(!metro.eof())
       {
        getline(metro,line,' ');
        if (line==Origen) {
          getline(metro,line,'\n');
          std::cout <<line;
        } else {
          getline(metro,line,'\n');
        }
      }
      metro.close();
     } else {
       r(Origen,Destino);
     }
    }else if(Argumento=="-l"){
        std::ifstream is("metro.txt");
        char c;while (is.get(c)){std::cout << c;}
  is.close();
    }else{
     cout<<"Error 404 Not Found"<<endl;
    }
    cout <<endl;
    return 0;
}

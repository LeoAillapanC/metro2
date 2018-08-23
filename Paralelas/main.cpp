  #include <cstdlib>
  #include <iostream>
  #include <string>
  #include <fstream>
  #include <queue>

struct station {
    std::string sigla;
    std::string name;
  };
struct combinar {
      std::string sigla;
      std::string name;
      std::string o;
      std::string d;
};
using namespace std;


  string cambio(string sigla){if(sigla== "SP")  {sigla="SO";}else if(sigla== "SO") {sigla="SP";}else if(sigla== "LH") {sigla="HE";}
    else if(sigla== "HE") {sigla="LH";}    else if(sigla== "BA")  {sigla="BQ";}    else if(sigla== "BQ") {sigla="BA";}    else if(sigla== "LE") {sigla="LEN";}    else if(sigla== "LEN") {sigla="LE";}    else if(sigla== "TB") {sigla="TOB";}    else if(sigla== "TOB") {sigla="TB";}    else if(sigla== "LC") {sigla="LCI";}    else if(sigla== "LCI") {sigla="LC";}
else if(sigla== "AN") {sigla="NA";}    else if(sigla== "NA") {sigla="AN";}    else if(sigla== "FR") {sigla="FRA";}   else if(sigla== "VMA") {sigla="VIM";}  else if(sigla== "VIM") {sigla="VMA";}    else if(sigla== "VVA") {sigla="VV";} else if(sigla== "VV") {sigla="VVA";}    else if(sigla== "NU") {sigla="NUO";}
    else if(sigla== "NUO") {sigla="NU";}  return sigla;}

void unalinea (queue<station> &X, string O, string D){
    bool flag=true,flags=false;
    queue<station>AUX;
    queue<station>RAUX;
    AUX=X;
    station aux;

    while (!AUX.empty()) {
      aux = AUX.front();
      if (aux.sigla==O) {
        if(flags==false){
          flags=true;}
          else{flags=false;}
        }
        if (aux.sigla==D) {
          flag=false;
          if(flags==false){
            flags=true;}
            else{flags=false;}
          }
      if(flags==true){
        RAUX.push(aux);
      }else if (flags==true && flag==true ){
        std::cout << aux.name << ' ';
      }
      std::cout << aux.name << ' ';
      AUX.pop();
    }
    if (flag=false) {
      while (!RAUX.empty()) {
        aux = RAUX.front();
        std::cout << aux.name << ' ';
        RAUX.pop();
      }

    }
}


  void recorrer(std::string O,std::string D) {
    int i=0,c=0,posicion;
    station aux;
    combinar auxiliar;
    ifstream myfile,fixero;
    fixero.open("metro.txt");
      string l,line,linea, lineao, linead, ori, des, flag,cadena,auxStr,auxStr2;
      std::queue<station> linea1;
      std::queue<station> linea2;
      std::queue<station> linea4;
    std::queue<station> linea4a;
    std::queue<station> linea5;
    std::queue<station> linea6;
    std::queue<station> ruta;
    std::queue<station> combinaciones;

    while(!fixero.eof())
{
    		getline(fixero,l);
    		posicion=l.find(" ");
    		auxStr = l.substr(0,posicion);
    		posicion=l.find(" ")+1;
    		auxStr2 =l.substr(posicion);
    		posicion=auxStr2.find(" ");
    		if(auxStr=="Línea")
    		{
    			posicion=auxStr2.find(" ");
    			auxStr2=auxStr2.substr(0,posicion);
          flag=auxStr2;

    		}
    		else
    		{
          posicion=auxStr2.find("\n");
    			auxStr2=auxStr2.substr(0,posicion);
          if (flag=="1") {
            aux.sigla=auxStr;
            aux.name=auxStr2;
            linea1.push(aux);

          }
          if (flag=="2") {
            aux.sigla=auxStr;
            aux.name=auxStr2;
            linea2.push(aux);

          }
          if (flag=="4") {
            aux.sigla=auxStr;
            aux.name=auxStr2;
            linea4.push(aux);

          }
          if (flag=="4a") {
            aux.sigla=auxStr;
            aux.name=auxStr2;
            linea4a.push(aux);

          }if (flag=="6") {
            aux.sigla=auxStr;
            aux.name=auxStr2;
            linea6.push(aux);

          }if (flag=="5") {
            aux.sigla=auxStr;
            aux.name=auxStr2;
            linea5.push(aux);
          }
          if (auxStr==D){
            flag=linead;
            //std::cout << flag << aux.sigla << aux.name << '\n';
          }
          if (auxStr==O){
            flag=lineao;
            //std::cout << flag << aux.sigla << aux.name << '\n';
          }
    		}
}
fixero.close();
unalinea(linea1,O,D);
/*cout <<ori << endl;
cout <<lineao << endl;
cout <<des << endl;
cout <<linead << endl;
cout <<c << endl;*/
}

  int main(int argc, char** argv) {
     string Argumento = argv[1];
     if(Argumento=="-v"){
     cout<<"Leonardo Aillapan Cuellar"<<endl;
     cout<<"Diego Pino Contreras"<<endl;
     cout<<"Jesús Zagal Velozo"<<endl;
     }else if(Argumento=="-f"){
     string Origen = argv[2];
     string Destino = argv[3];
      //cout<<"Ruta"<<endl<<Origen<<endl<<Destino<<endl;
      recorrer(Origen,Destino);
     }else if(Argumento=="-l"){
         std::ifstream is("metro.txt");
         char c;while (is.get(c)){std::cout << c;}
    is.close();
     }else{
      cout<<"Error 404 Not Found"<<endl;
     }
     return 0;
  }

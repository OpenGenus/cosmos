#include "dialog.h"
#include "ui_dialog.h"
#include "nodo.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <sstream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
const int k = 2;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
Node* newNode(vector<double> arr,int re){
    int k=2;
    Node* temp = new Node;
    temp->altura=re;
    for (int i=0; i<k; i++){
       temp->point.push_back(arr[i]);
    }
    temp->left = temp->right = NULL;
    return temp;
}


Node* insertar(Node *root, vector<double> point, unsigned alt)   ///////////////////////------ 2 -------/////////////
{
    int k=2;
    if (root == NULL)
       return newNode(point,alt);

    unsigned compara = alt % k;

    if (point[compara] < (root->point[compara])){
        root->left  = insertar(root->left, point,   alt + 1);
    }
    else{
        root->right = insertar(root->right, point, alt + 1);
    }
    return root;
}
Node*insertar_(Node *root, vector<double> point) ///////// Pasa toda la lista de puntos //////////////----- 1 -----///////////
{
    return insertar(root, point, 0);
}

bool mismo_punto(vector<double> point1,  vector<double> point2)
{
    int k=2;
    for (int i = 0; i < k; ++i)
        if (point1[i] != point2[i])
            return false;

    return true;
}
bool buscar(Node* root, vector<double> point, unsigned alt)
{
    int k=2;
    if (root == NULL)
        return false;
    if (mismo_punto(root->point, point))
        return true;


    unsigned compara = alt % k;
    if (point[compara] < root->point[compara])
        return buscar(root->left, point, alt + 1);

    return buscar(root->right, point, alt + 1);
}
bool buscar_(Node* root, vector<double> point)
{
    return buscar(root, point, 0);
}


void imprimir_1(vector< vector <double> > &v,int dimension){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<"(";
        for (int j = 0; j < dimension; j++)
        {
            cout<<v[i][j]<<",";
        }
        cout<<")"<<endl;
   }
}
void preOrden(Node* root_,vector<vector<double>>& lineas) {
    vector<double> linea;
    cout<<"("<<root_->point[0]<<","<<root_->point[1]<<" "<<")"<<"altura:"<<root_->altura<<endl;
                 if(root_->left!=NULL && root_->right!=NULL ){
                     cout<<"Entro dos hijos"<<endl;

                     if(root_->altura%2==0){ /////////////FILA X //////////
                         //mantiene y
                        linea.push_back(root_->point[0]);
                        linea.push_back(root_->left->point[1]);
                        linea.push_back(-3.0);
                        linea.push_back(root_->left->point[1]);
                        lineas.push_back(linea);
                        cout<<linea.size()<<" "<<"tamaño de linea";
                        cout<<lineas.size()<<" "<<"tamaño lineas";
                        linea.clear();
                        linea.push_back(root_->point[0]);
                        linea.push_back(root_->right->point[1]);
                        linea.push_back(root_->right->point[0]+6.0);
                        linea.push_back(root_->right->point[1]);
                        lineas.push_back(linea);
                        cout<<linea.size()<<" "<<"tamaño de linea";
                        cout<<lineas.size()<<" "<<"tamaño lineas";
                        linea.clear();


                     }
                     if(root_->altura%2!=0){ ////FILA Y///////////////
                         linea.push_back(root_->left->point[0]);
                         linea.push_back(root_->point[1]);
                         linea.push_back(root_->left->point[0]);
                         linea.push_back(-6.0);
                         lineas.push_back(linea);
                         cout<<linea.size()<<" "<<"tamaño de linea";
                         cout<<lineas.size()<<" "<<"tamaño lineas";
                         linea.clear();
                         linea.push_back(root_->right->point[0]);
                         linea.push_back(root_->point[1]);
                         linea.push_back(root_->right->point[0]);
                         linea.push_back(root_->right->point[0]+15.0);
                         lineas.push_back(linea);
                         cout<<linea.size()<<" "<<"tamaño de linea";
                         cout<<lineas.size()<<" "<<"tamaño lineas";
                         linea.clear();
                     }
                 }
                 if(root_->right!=NULL && root_->left==NULL){
                     cout<<"caso hijo derecho";
                    if(root_->altura%2==0){
                     linea.push_back(root_->point[0]);
                     linea.push_back(root_->right->point[1]);
                     linea.push_back(root_->right->point[0]+6.0);
                     linea.push_back(root_->right->point[1]);
                     lineas.push_back(linea);
                     cout<<linea.size()<<" "<<"tamaño de linea";
                     cout<<lineas.size()<<" "<<"tamaño lineas";
                     linea.clear();
                    }
                 }
                 if(root_->right==NULL && root_->left!=NULL){
                    cout<<"caso hijo izquierdo";
                     if(root_->altura%2==0){
                     linea.push_back(root_->point[0]);
                     linea.push_back(root_->left->point[1]);
                     linea.push_back(root_->left->point[0]+6.0);
                     linea.push_back(root_->left->point[1]);
                     lineas.push_back(linea);
                     cout<<linea.size()<<" "<<"tamaño de linea";
                     cout<<lineas.size()<<" "<<"tamaño lineas";
                     linea.clear();
                     }
                 }
       if (root_->left != NULL)
           preOrden(root_->left,lineas);
       if (root_->right != NULL)
           preOrden(root_->right,lineas);

}
void Dialog::paintEvent(QPaintEvent *e){
    srand( time( NULL ) );
    int iSecret, iGuess;

    ////////////////////PARSEO CON ARCHIVO CSV //////////////////7

    vector<vector<double>> puntos;
    vector <double> punto;
    vector <double> puntosY;
    int k=2;
    QFile file("/home/andre/QT_archivos/kd_dinujo/kd_tree_dibujo/country_capitals.csv");
     if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << file.errorString();
            //return 1;
        }
        double x,y;
        QStringList wordList;
        QStringList wordList2;
        QString a;
        int i=0;
        while (!file.atEnd()) {
              //  using the time seed from srand explanation

            QString line = file.readLine();
            wordList=line.split(",");
            if(wordList.size()==2){
                x=wordList.at(0).toDouble();
                //x=(x-41.0)*100.0;
                y=wordList.at(1).toDouble();
                //y=(y+87.0)*100.0;
                punto.push_back(x);
                punto.push_back(y);
                puntos.push_back(punto);
                punto.clear();
         }

            double c;
            i++;
        }

    ///////////////////////////////////////////////////////////////////

    /*
    /////////////GENERAR_PUNTOS-aleatorios////////////////////////////

        srand( unsigned(time(NULL)));
        vector< vector<double>> puntos;
        vector<double> punto;
        double u;
        //cout<<"hola"<<endl;
        int dimension=2;
        for (int i = 0; i < 10; ++i)
        {
                for (int y = 0; y < dimension; ++y)
                {
                    u=(double)(rand()%90+10)/100;
                    punto.push_back(u);
                }
                puntos.push_back(punto);
                punto.clear();

         }

    /////////////////////////////////////////////////////////////////////
    */
     //imprimir_1(puntos,k);

      /*
      //////////////////////////////////POR USUARIO////////////////////////////7
        vector<vector<double>> puntos_u;
        vector<double> l;
        l.push_back(3.0);
        l.push_back(6.0);
        vector<double> b;
        b.push_back(17.0);
        b.push_back(15.0);
        vector<double> c;
        c.push_back(13.0);
        c.push_back(15.0);
        vector<double> d;
        d.push_back(6.0);
        d.push_back(12.0);
        vector<double> u;
        u.push_back(9.0);
        u.push_back(1.0);
        vector<double> f;
        f.push_back(2.0);
        f.push_back(7.0);
        vector<double> g;
        g.push_back(10.0);
        g.push_back(19.0);
        puntos_u.push_back(l);
        puntos_u.push_back(b);
        puntos_u.push_back(c);
        puntos_u.push_back(d);
        puntos_u.push_back(u);
        puntos_u.push_back(f);
        puntos_u.push_back(g);
        //imprimir_1(puntos_u,2);
        ////////////////////////////////////////7
        */
        struct Node *root = NULL;  ///inicializo la raiz//////////
        int n=puntos.size();  ////cambiar puntos por puntos_u
        for (int j=0; j<n;j++)
               root=insertar_(root,puntos[j]);

        ///////////////// DIBUJO ///////////////////////////////
        QPainter painter(this);
        //painter.translate(41.0,-.0);
        painter.translate(this->rect().center());
        //painter.setWindow(41,-87,200,200);
        //Spainter.translate(this->rect().center());
        //QTransform transform;
        //transform.rotate(+270.0);
        //painter.setWorldTransform(transform);
        //painter.translate(+50.0,+50.0);
        //painter.drawText(pos,tr("Sales"));
        painter.scale(-2.0,-2.0);
        QPen pointpen(Qt::red);
        pointpen.setWidth(1.2);

        QPen linepen(Qt::black);
        linepen.setWidth(0.3);
        vector<vector<double>> media_b;
        painter.setPen(linepen);
        painter.drawLine(root->point[0],root->point[1]+30,root->point[0],root->point[1]-30);
        preOrden(root,media_b);
        cout<<media_b.size()<<"tamaño"<<endl;
        for(int j=0;j<media_b.size();j++){
            painter.drawLine(media_b[j][0],media_b[j][1],media_b[j][2],media_b[j][3]);

        }
        double num;
        painter.setPen(pointpen);
        cout<<"si funciona"<<puntos.size()<<endl;
        for(int i=0;i<puntos.size();i++){
            int nume = (rand()%30) + 20 ;
            cout<<nume<<"numero aleatorio"<<endl;

            QPoint p1;
            p1.setX(puntos[i][0]);
            cout<<puntos[i][0]<<endl;
            p1.setY(puntos[i][1]);
            cout<<puntos[i][1]<<endl;
            painter.drawPoint(p1);
            //painter.drawLine(1);

        }
        /*
         *
        QPen pointpens(Qt::blue);
        pointpens.setWidth(1.2);
        painter.setPen(pointpens);
        for(int i=puntos.size();i<puntos.size();i++){

                QPoint p2;
                p2.setX(puntos[i][0]);
                p2.setY(puntos[i][1]);
                painter.drawPoint(p2);
                //painter.drawLine(1);

            }
*/


        /*
    painter.setPen(pointpen);
    QPoint p1;
    p1.setX(41.0);
    p1.setY(-87.0);
    painter.drawPoint(p1);


     /*
    QPoint p1;
    p1.setX(10);
    p1.setY(10);

    QPoint p2;
    p2.setX(100);
    p2.setY(100);
    */
    //painter.drawLine(10,10,100,100);
    //painter.setPen(pointpen);
    //painter.drawPoint(p1);
    //painter.drawPoint(p2);
}

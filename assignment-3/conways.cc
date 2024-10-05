#include <iostream>
using namespace std;

char** columns = new char*[1];
int l = 0;
int rowLength;

void displayMatrix();
void addRowToGrid(char *row);
void addRow(string row);
void read();
void readCommand();
void propagate();
int getDead(int c,int r,char** temp);
int getAlive(int c, int r,char** temp);
char** replicateMatrix();
void deleteMatrix(char** columnsTempMat);


int main(){
    read();
    deleteMatrix(columns);
    return 0;
}


void displayMatrix() {
    for(int i = 0; i<rowLength;++i) cout << "|";
    cout << endl;
    for (int i = 0; i < l; ++i) {
        for(int j=0;j<rowLength;++j){
            cout << columns[i][j];
        }
        cout << endl;
    }
    for(int i = 0; i<rowLength;++i) cout << "|";
    cout << endl;
}

void addRowToGrid(char *row){
    if(l == 0){
        columns[0] = row;
        l++;
    }
    else{
        //migration
        char** columns2 = new char*[l+1];
        for(int i = 0; i < l; i++){
            columns2[i] = columns[i];
        }
        columns2[l] = row;
        delete[] columns;
        columns = columns2;
        l++;
    }
}

void addRow(string row){
    char* cells = new char[row.size()];
    for(std::string::size_type i = 0; i<row.size(); ++i){
        cells[i] = row[i];
    }
    rowLength = row.size();
    addRowToGrid(cells);
}

void read(){
    string row = "";
    while(getline(cin,row) && row != "x"){
        addRow(row);
    }
    readCommand();
}

void readCommand(){
    string row = "";
    while(getline(cin, row)){
        for(std::string::size_type i = 0;i<row.size();++i){
            if(row[i] == 'p'){
                displayMatrix();
            }
            if(row[i] == 's'){
                propagate();
            }
        }
    }
}

void propagate(){
    char** temp = replicateMatrix();
    for (int i = 0; i < l; ++i) {
        for(int j=0;j<rowLength;++j){
            // int dead = getDead(i,j, temp);
            int alive = getAlive(i,j, temp);
            if(alive < 2){
                columns[i][j] = '.';
            }
            else if(alive > 3){
                columns[i][j] = '.';
            }
            else if(alive == 3){
                columns[i][j] = 'O';
            }
        }
    }
    deleteMatrix(temp);
}

int getDead(int c, int r, char** temp){
    int dead = 0;

    //Cardinal
    if((r - 1) >=0 ){
        if(temp[c][r-1] == '.'){
            dead++;
        }
    }
    if((r + 1) <= rowLength-1){
        if(temp[c][r+1] == '.'){
            dead++;
        }
    }
    if((c - 1) >=0 ){
        if(temp[c-1][r] == '.'){
            dead++;
        }
    }
    if((c + 1) <= l-1){
        if(temp[c+1][r] == '.'){
            dead++;
        }
    }

    //Ordinal
    if(((r-1) >= 0) && ((c-1 >=0))){ //top-left
        if(temp[c-1][r-1] == '.'){  
            dead++;
        }
    }
    if(((r-1) >= 0) && ((c+1 <= l-1))){ //bottom-left
        if(temp[c+1][r-1] == '.'){  
            dead++;
        }
    }
    if(((r+1) <= rowLength-1) && ((c-1 >=0))){ //top-right
        if(temp[c-1][r+1] == '.'){  
            dead++;
        }
    }
    if(((r+1) <= rowLength-1) && ((c+1 <= l-1))){ //bottom-right
        if(temp[c+1][r+1] == '.'){  
            dead++;
        }
    }

    return dead;

}

int getAlive(int c, int r, char** temp){
    int alive = 0;

    //Cardinal
    if((r - 1) >=0 ){
        if(temp[c][r-1] == 'O'){
            alive++;
        }
    }
    if((r + 1) <= rowLength-1){
        if(temp[c][r+1] == 'O'){
            alive++;
        }
    }
    if((c - 1) >=0 ){
        if(temp[c-1][r] == 'O'){
            alive++;
        }
    }
    if((c + 1) <= l-1){
        if(temp[c+1][r] == 'O'){
            alive++;
        }
    }

    //Ordinal
    if(((r-1) >= 0) && ((c-1 >=0))){ //top-left
        if(temp[c-1][r-1] == 'O'){  
            alive++;
        }
    }
    if(((r-1) >= 0) && ((c+1 <= l-1))){ //bottom-left
        if(temp[c+1][r-1] == 'O'){  
            alive++;
        }
    }
    if(((r+1) <= rowLength-1) && ((c-1 >=0))){ //top-right
        if(temp[c-1][r+1] == 'O'){  
            alive++;
        }
    }
    if(((r+1) <= rowLength-1) && ((c+1 <= l-1))){ //bottom-right
        if(temp[c+1][r+1] == 'O'){  
            alive++;
        }
    }

    return alive;

}

char** replicateMatrix() {
    char** newColumns = new char*[l];
    
    for(int i = 0; i < l; ++i) {
        newColumns[i] = new char[rowLength];
        
        for(int j = 0; j < rowLength; ++j) {
            newColumns[i][j] = columns[i][j];
        }
    }

    return newColumns;
}

void deleteMatrix(char** columnsTempMat) {
    for (int i = 0; i < l; ++i) {
        delete[] columnsTempMat[i]; // Delete each row
    }
    delete[] columnsTempMat; // Delete the array of pointers (to each row)
}

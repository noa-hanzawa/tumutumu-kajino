#include <iostream>
#include <cstdlib>     
using namespace std;

int main() { 
  int playnum;  int play1;  int player;
  
  cout<<"ツムツムカジノへようこそ"<<endl;
  cout<<"あなたの所持金は５０００ツムです"<<endl;
  int play1money=5000;
  cout<<"1から10までの数字で何が出るか予想してください。"<<endl;
  cout<<"何回プレイしますか？"<<endl;
  cin>>playnum;
  cout<<playnum<<"回ですね"<<endl;
  cout<<"ゲームを開始します"<<endl;

  
  for(int i=1; i<=playnum; i++){
    cout<<i<<"回目"<<endl;
    for(;;){
      cout<<"掛け金を入力してください"<<endl;
      cin>>play1;
      if(play1>play1money){
        cout<<"そんなに金持ってないだろ"<<endl;
      }
      if(play1<=play1money){
        cout<<"掛け金は"<<play1<<endl;
        break;
      }
    }
    cout<<"予想する数字は"<<endl;
    cin>>player;
    int a=rand () % 10+1 ;
    cout << a <<"が出ました"<< endl;
    if(a==player){
      cout<<"当たりました。"<<endl;
      cout<<"持ち金に"<<play1*2<<"追加されるマス"<<endl;
      play1money=play1money+play1*2;
      cout<<"現在の持ち金は"<<play1money<<"です"<<endl;
    }else{
      cout<<"残ね～ンハズレ"<<endl;
      cout<<"掛け金分、持ち金が減ります"<<endl;
      play1money=play1money-play1;
      cout<<"現在の持ち金は"<<play1money<<"です"<<endl;
   }
    if(play1money<=0)  break;
   }
   if(play1money<=0){
     cout<<"持ち金がなくなりました。\n　破産！！！ "<<endl;
   }
}
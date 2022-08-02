#include <iostream>
#include <cstdlib>     
using namespace std;

int main() { 
  int playnum;  //何回プレイするか
  string player1name;  //プレイヤー1の名前
  string player2name;  //プレイヤー２の名前 
  int play1money=5000; //プレイヤー１の持ち金
  int play2money=5000; //プレイヤー2の持ち金
  int play1;  int player1; //プレイヤー１の掛け金、予想する数字
  int play2;  int player2; //プレイヤー２の掛け金、予想する数字
  
  cout<<"ツムツムカジノへようこそ!"<<"あなた方のお名前は？"<<endl;
  cout<<"1人目"<<endl;
  cin>>player1name;
  cout<<"2人目"<<endl;
  cin>>player2name;
  cout<<player1name<<"さんと"<<player2name<<"さんですね。\n今からルール説明をします。"<<endl;
  cout<<"あなた方の最初の所持金は5000ツムです。"<<endl;
  cout<<"今から、1から10までの数字が出るので、何が出るか予想してください。"<<endl;
  cout<<"当たった場合、掛け金の2倍が貰えます。\nはずれた場合,掛け金分が持ち金から引かれます。\n 最終的に持ち金が多い方の勝ちとなります。\nゲームの途中で持ち金が0になった場合失格となり、負けです。\n では、スタートします。"<<endl;
  cout<<"何回プレイしますか？"<<endl;
  cin>>playnum;
  cout<<playnum<<"回ですね"<<endl;
  cout<<"ゲームを開始します"<<endl;

  
  for(int i=1; i<=playnum; i++){
    cout<<i<<"回目"<<endl;

    
    for(;;){
      cout<<player1name<<"さん、掛け金を入力してください"<<endl;
      cin>>play1;
      if(play1>play1money){
        cout<<player1name<<"そんなに金持ってないだろ"<<endl;
      }
      if(play1<=play1money){
        cout<<player1name<<"さんの掛け金は"<<play1<<"です"<<endl;
        break;
      }
    }

    for(;;){
      cout<<player2name<<"さん、掛け金を入力してください"<<endl;
      cin>>play2;
      if(play2>play2money){
        cout<<player2name<<"そんなに金持ってないだろ"<<endl;
      }
      if(play2<=play2money){
        cout<<player2name<<"さんの掛け金は"<<play2<<"です"<<endl;
        break;
        }  
    }

    
    cout<<player1name<<"さん予想する数字は"<<endl;
    cin>>player1;
    cout<<player2name<<"さん予想する数字は"<<endl;
    cin>>player2;
    int a=rand () % 10+1 ;
    cout << a <<"が出ました"<< endl;
     if(a==player1&&a==player2){
      cout<<"2人とも当たりました。"<<endl;
      cout<<player1name<<"さんは持ち金に"<<play1*2<<"追加されるマス"<<endl;
      cout<<player2name<<"さんは持ち金に"<<play2*2<<"追加されるマス"<<endl; 
      play1money=play1money+play1*2;
      play2money=play2money+play2*2;
      cout<<player1name<<"さんの現在の持ち金は"<<play1money<<"です"<<endl;
      cout<<player2name<<"さんの現在の持ち金は"<<play2money<<"です"<<endl; 
    }else if(a==player1){
      cout<<player1name<<"さん当たり!"<<player2name<<"さんはずれ"<<endl;
      cout<<player1name<<"さんは持ち金に"<<play1*2<<"追加されるマス"<<endl;
      play1money=play1money+play1*2;
      cout<<player2name<<"さんは持ち金が"<<play2<<"減ります"<<endl;
      play2money=play2money-play2;
      cout<<player1name<<"さんの現在の持ち金は"<<play1money<<"です"<<endl;
      cout<<player2name<<"さんの現在の持ち金は"<<play2money<<"です"<<endl; 
    }else if(a==player2){
      cout<<player2name<<"さん当たり!"<<player1name<<"さんはずれ"<<endl;
      cout<<player2name<<"さんの持ち金に"<<play2*2<<"追加されるマス"<<endl;
      play2money=play2money+play2*2;
      cout<<player1name<<"さんは持ち金が"<<play1<<"減ります"<<endl;
      play1money=play1money-play1;
      cout<<player1name<<"さんの現在の持ち金は"<<play1money<<"です"<<endl;
      cout<<player2name<<"さんの現在の持ち金は"<<play2money<<"です"<<endl;
    }else if(a!=player1&&a!=player2){
      cout<<"残ね～ン2人ともハズレ!!"<<endl;
      cout<<"掛け金分、持ち金が減ります"<<endl;
      play1money=play1money-play1;
      play2money=play2money-play2;
      cout<<player1name<<"さんの現在の持ち金は"<<play1money<<"です"<<endl;
      cout<<player2name<<"さんの現在の持ち金は"<<play2money<<"です"<<endl;
    }
    if(play1money<=0||play2money<=0) break;
  }

  
  if(play1money>play2money){
    cout<<player1name<<"さんの勝利"<<endl;
  }
  if(play2money>play1money){
    cout<<player2name<<"さんの勝利"<<endl;
  }
  if(play1money==play2money){
    cout<<"引き分け"<<endl;
  }
  if(play1money<=0){
     cout<<player1name<<"さんの持ち金がなくなりました。"<<player1name<<"破産!!!"<<player2name<<"さんの勝利"<<endl;
   }
  if(play2money<=0){
     cout<<player2name<<"さんの持ち金がなくなりました。"<<player2name<<"破産!!!"<<player2name<<"さんの勝利"<<endl;
   }
}

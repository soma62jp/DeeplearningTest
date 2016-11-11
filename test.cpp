/* 
 * nnet test
 * 2016.06.06
 * author:soma62jp
 *                  */


#include "test.h"

//using namespace std;


nnet::nnet(const int &inum,
	const int &hnum1,
	const int &hnum2,
	const int &hnum3,
	const int &hnum4,
	const int &hnum5,
	const int &hnum6,
	const int &hnum7,
	const int &hnum8,
	const int &hnum9,
	const int &hnum10,
	const int &onum,
	const int &pnum):

	  inputnum(inum)
	 ,hiddennum1(hnum1)
	 ,hiddennum2(hnum2)
	 ,hiddennum3(hnum3)
	 ,hiddennum4(hnum4)
	 ,hiddennum5(hnum5)
	 ,hiddennum6(hnum6)
	 ,hiddennum7(hnum7)
	 ,hiddennum8(hnum8)
	 ,hiddennum9(hnum9)
	 ,hiddennum10(hnum10)
	 ,outputnum(onum)
	 ,patternnum(pnum)
	 ,ALPHA(0.8)
{

	// 初期化
	H1i.resize(hiddennum1 + 1);           // bias項
	fill(H1i.begin(), H1i.end(), 0);

	H2i.resize(hiddennum2 + 1);           // bias項
	fill(H2i.begin(), H2i.end(), 0);

	H3i.resize(hiddennum3 + 1);           // bias項
	fill(H3i.begin(), H3i.end(), 0);

	H4i.resize(hiddennum4 + 1);           // bias項
	fill(H4i.begin(), H4i.end(), 0);

	H5i.resize(hiddennum5 + 1);           // bias項
	fill(H5i.begin(), H5i.end(), 0);

	H6i.resize(hiddennum6 + 1);           // bias項
	fill(H6i.begin(), H6i.end(), 0);

	H7i.resize(hiddennum7 + 1);           // bias項
	fill(H7i.begin(), H7i.end(), 0);

	H8i.resize(hiddennum8 + 1);           // bias項
	fill(H8i.begin(), H8i.end(), 0);

	H9i.resize(hiddennum9 + 1);           // bias項
	fill(H9i.begin(), H9i.end(), 0);

	H10i.resize(hiddennum10 + 1);           // bias項
	fill(H10i.begin(), H10i.end(), 0);


	Oi.resize(outputnum);
	fill(Oi.begin(), Oi.end(), 0);


	E1.resize(hiddennum1);
	fill(E1.begin(), E1.end(), 0);

	E2.resize(hiddennum2);
	fill(E2.begin(), E2.end(), 0);

	E3.resize(hiddennum3);
	fill(E3.begin(), E3.end(), 0);

	E4.resize(hiddennum4);
	fill(E4.begin(), E4.end(), 0);

	E5.resize(hiddennum5);
	fill(E5.begin(), E5.end(), 0);

	E6.resize(hiddennum6);
	fill(E6.begin(), E6.end(), 0);

	E7.resize(hiddennum7);
	fill(E7.begin(), E7.end(), 0);

	E8.resize(hiddennum8);
	fill(E8.begin(), E8.end(), 0);

	E9.resize(hiddennum9);
	fill(E9.begin(), E9.end(), 0);

	E10.resize(hiddennum10);
	fill(E10.begin(), E10.end(), 0);

	E11.resize(outputnum);
	fill(E11.begin(), E11.end(), 0);


	// pattern*input
	Ii.resize(patternnum);				// ()内の数字が要素数になる
	for( int i=0; i<patternnum; i++ ){
		Ii[i].resize(inputnum);
		std::fill(Ii[i].begin(), Ii[i].end(), 0);
	}

	// pattern*output
	Ti.resize(patternnum);
	for(int i=0;i<patternnum;i++){
		Ti[i].resize(outputnum);
		std::fill(Ti[i].begin(), Ti[i].end(), 0);
	}

	// hidden1*input
	W1.resize(hiddennum1);
	for( int i=0; i<hiddennum1; i++ ){
		W1[i].resize(inputnum + 1);     // bias項
		std::fill(W1[i].begin(), W1[i].end(), 0);
	}

	// hidden2*hidden1
	W2.resize(hiddennum2);
	for( int i=0; i<hiddennum2; i++ ){
		W2[i].resize(hiddennum1 + 1);     // bias項
		std::fill(W2[i].begin(), W2[i].end(), 0);
	}

	W3.resize(hiddennum3);
	for( int i=0; i<hiddennum3; i++ ){
		W3[i].resize(hiddennum2 + 1);     // bias項
		std::fill(W3[i].begin(), W3[i].end(), 0);
	}

	W4.resize(hiddennum4);
	for( int i=0; i<hiddennum4; i++ ){
		W4[i].resize(hiddennum3 + 1);     // bias項
		std::fill(W4[i].begin(), W4[i].end(), 0);
	}

	W5.resize(hiddennum5);
	for( int i=0; i<hiddennum5; i++ ){
		W5[i].resize(hiddennum4 + 1);     // bias項
		std::fill(W5[i].begin(), W5[i].end(), 0);
	}

	W6.resize(hiddennum6);
	for( int i=0; i<hiddennum6; i++ ){
		W6[i].resize(hiddennum5 + 1);     // bias項
		std::fill(W6[i].begin(), W6[i].end(), 0);
	}

	W7.resize(hiddennum7);
	for( int i=0; i<hiddennum7; i++ ){
		W7[i].resize(hiddennum6 + 1);     // bias項
		std::fill(W7[i].begin(), W7[i].end(), 0);
	}

	W8.resize(hiddennum8);
	for( int i=0; i<hiddennum8; i++ ){
		W8[i].resize(hiddennum7 + 1);     // bias項
		std::fill(W8[i].begin(), W8[i].end(), 0);
	}

	W9.resize(hiddennum9);
	for( int i=0; i<hiddennum9; i++ ){
		W9[i].resize(hiddennum8 + 1);     // bias項
		std::fill(W9[i].begin(), W9[i].end(), 0);
	}

	W10.resize(hiddennum10);
	for( int i=0; i<hiddennum10; i++ ){
		W10[i].resize(hiddennum9 + 1);     // bias項
		std::fill(W10[i].begin(), W10[i].end(), 0);
	}

	// output*hidden
	W11.resize(outputnum);
	for( int i=0; i<outputnum; i++ ){
		W11[i].resize(hiddennum10 + 1);    // bias項
		std::fill(W11[i].begin(),W11[i].end(), 0);
	}

	//initialize parameter
	// 重みのランダマイズ
	srand((unsigned int)time(NULL));

	for(int i=0;i<(int)W1.size();i++){
		for(int j=0;j<(int)W1[i].size();j++){
			W1[i][j]=urand();
		}
	}

	for(int i=0;i<(int)W2.size();i++){
		for(int j=0;j<(int)W2[i].size();j++){
			W2[i][j]=urand();
		}
	}

	for(int i=0;i<(int)W3.size();i++){
		for(int j=0;j<(int)W3[i].size();j++){
			W3[i][j]=urand();
		}
	}

	for(int i=0;i<(int)W4.size();i++){
		for(int j=0;j<(int)W4[i].size();j++){
			W4[i][j]=urand();
		}
	}

	for(int i=0;i<(int)W5.size();i++){
		for(int j=0;j<(int)W5[i].size();j++){
			W5[i][j]=urand();
		}
	}

	for(int i=0;i<(int)W6.size();i++){
		for(int j=0;j<(int)W6[i].size();j++){
			W6[i][j]=urand();
		}
	}

	for(int i=0;i<(int)W7.size();i++){
		for(int j=0;j<(int)W7[i].size();j++){
			W7[i][j]=urand();
		}
	}

	for(int i=0;i<(int)W8.size();i++){
		for(int j=0;j<(int)W8[i].size();j++){
			W8[i][j]=urand();
		}
	}

	for(int i=0;i<(int)W9.size();i++){
		for(int j=0;j<(int)W9[i].size();j++){
			W9[i][j]=urand();
		}
	}

	for(int i=0;i<(int)W10.size();i++){
		for(int j=0;j<(int)W10[i].size();j++){
			W10[i][j]=urand();
		}
	}

	for(int i=0;i<(int)W11.size();i++){
		for(int j=0;j<(int)W11[i].size();j++){
			W11[i][j]=urand();
		}
	}

}

nnet::~nnet()
{

}

void  nnet::setAlpha(const double &value)
{
	ALPHA = value;
}

void nnet::setErrorEv(const double &value)
{
	ERROREV = value;
}

void  nnet::setInData(const int &pnum,const int &i,const double &value)
{
	if(pnum>=patternnum || i>=inputnum){
		outlog("can't set Indata.");
		return;
	}
	Ii[pnum][i] = value;
}

void nnet::setTeachData(const int &pnum,const int &i,const double &value)
{
	if(pnum>=patternnum || i>=outputnum){
		outlog("can't set Teachdata.");
		return;
	}
	Ti[pnum][i] = value;
}

void nnet::setPredictData(const int &i,const double &value)
{
	if(i>=inputnum){
		outlog("can't set Predictdata.");
		return;
	}
	Ii[patternnum-1][i] = value;
}


void nnet::foward_propagation(const int &pnum)
{
	int i,j;
	double sum;
	std::vector<double> wrkOi;

	wrkOi.resize(outputnum);

	// 入力層ー＞隠れ層
	for(i=0;i<hiddennum1;i++){
		sum=0;
		for(j=0;j<inputnum;j++){
			// 重み×入力値
			sum+=W1[i][j]*Ii[pnum][j];
		}
		sum+=W1[i][inputnum];						// bias項
		// 重み×入力値の総和にバイアス項を足してアクティベーション関数に通したものが中間層入力
		H1i[i] = activationFunc(sum) * DROPOUT;
	}

	for(i=0;i<hiddennum2;i++){
		sum=0;
		for(j=0;j<hiddennum1;j++){
			// 重み×入力値
			sum+=W2[i][j]*H1i[j];
		}
		sum+=W2[i][hiddennum1];						// bias項
		// 重み×入力値の総和にバイアス項を足してアクティベーション関数に通したものが中間層入力
		H2i[i] = activationFunc(sum) * DROPOUT;
	}

	for(i=0;i<hiddennum3;i++){
		sum=0;
		for(j=0;j<hiddennum2;j++){
			// 重み×入力値
			sum+=W3[i][j]*H2i[j];
		}
		sum+=W3[i][hiddennum2];						// bias項
		// 重み×入力値の総和にバイアス項を足してアクティベーション関数に通したものが中間層入力
		H3i[i] = activationFunc(sum) * DROPOUT;
	}

	for(i=0;i<hiddennum4;i++){
		sum=0;
		for(j=0;j<hiddennum3;j++){
			// 重み×入力値
			sum+=W4[i][j]*H3i[j];
		}
		sum+=W4[i][hiddennum3];						// bias項
		// 重み×入力値の総和にバイアス項を足してアクティベーション関数に通したものが中間層入力
		H4i[i] = activationFunc(sum) * DROPOUT;
	}

	for(i=0;i<hiddennum5;i++){
		sum=0;
		for(j=0;j<hiddennum4;j++){
			// 重み×入力値
			sum+=W5[i][j]*H4i[j];
		}
		sum+=W5[i][hiddennum4];						// bias項
		// 重み×入力値の総和にバイアス項を足してアクティベーション関数に通したものが中間層入力
		H5i[i] = activationFunc(sum) * DROPOUT;
	}

	for(i=0;i<hiddennum6;i++){
		sum=0;
		for(j=0;j<hiddennum5;j++){
			// 重み×入力値
			sum+=W6[i][j]*H5i[j];
		}
		sum+=W6[i][hiddennum5];						// bias項
		// 重み×入力値の総和にバイアス項を足してアクティベーション関数に通したものが中間層入力
		H6i[i] = activationFunc(sum) * DROPOUT;
	}

	for(i=0;i<hiddennum7;i++){
		sum=0;
		for(j=0;j<hiddennum6;j++){
			// 重み×入力値
			sum+=W7[i][j]*H6i[j];
		}
		sum+=W7[i][hiddennum6];						// bias項
		// 重み×入力値の総和にバイアス項を足してアクティベーション関数に通したものが中間層入力
		H7i[i] = activationFunc(sum) * DROPOUT;
	}

	for(i=0;i<hiddennum8;i++){
		sum=0;
		for(j=0;j<hiddennum7;j++){
			// 重み×入力値
			sum+=W8[i][j]*H7i[j];
		}
		sum+=W8[i][hiddennum7];						// bias項
		// 重み×入力値の総和にバイアス項を足してアクティベーション関数に通したものが中間層入力
		H8i[i] = activationFunc(sum) * DROPOUT;
	}

	for(i=0;i<hiddennum9;i++){
		sum=0;
		for(j=0;j<hiddennum8;j++){
			// 重み×入力値
			sum+=W9[i][j]*H8i[j];
		}
		sum+=W9[i][hiddennum8];						// bias項
		// 重み×入力値の総和にバイアス項を足してアクティベーション関数に通したものが中間層入力
		H9i[i] = activationFunc(sum) * DROPOUT;
	}

	for(i=0;i<hiddennum10;i++){
		sum=0;
		for(j=0;j<hiddennum9;j++){
			// 重み×入力値
			sum+=W10[i][j]*H9i[j];
		}
		sum+=W10[i][hiddennum9];						// bias項
		// 重み×入力値の総和にバイアス項を足してアクティベーション関数に通したものが中間層入力
		H10i[i] = activationFunc(sum) * DROPOUT;
	}

	// 隠れ層ー＞出力層
	for(i=0;i<outputnum;i++){
		sum=0;
		for(j=0;j<hiddennum10;j++){
			// 重み×中間層入力
			sum+=W11[i][j]*H10i[j];
		}
		sum+=W11[i][hiddennum10];						// bias項
		// 重み×中間層入力値の総和にバイアス項を足してアクティベーション関数に通したものが出力層
		//Oi[i]=outputFunc(sum);
		wrkOi[i]=sum;
	}

	// softmax 計算
	for(i=0;i<outputnum;i++){
		Oi[i]=outputFunc(wrkOi[i],wrkOi,outputnum);
	}

}

void nnet::back_propagation(const int &pnum)
{

	int i,j;
	double sum;

	// 重みの変化量[隠れ層ー＞出力層]を計算
	// 隠れ層の学習信号を計算
	for(i=0;i<outputnum;i++){
		// 出力層での誤差信号=(教師信号-出力）* f'(出力)
		// f'(出力)はシグモイド関数の微分
		E11[i]=(Ti[pnum][i]-Oi[i]) * outputFunc_diff(Oi[i]);
	}

	for(i=0;i<hiddennum10;i++){
		sum = 0;
		for(j=0;j<outputnum;j++){
			// 中間層での誤差信号=f'(隠れ層出力) * 隠れ層->出力層重み * 隠れ層<-出力層での誤差
			sum += W11[j][i]*E11[j];
		}
		E10[i] = sum * activationFunc_diff(H10i[i]);
	}

	for(i=0;i<hiddennum9;i++){
		sum = 0;
		for(j=0;j<outputnum;j++){
			// 中間層での誤差信号=f'(隠れ層出力) * 隠れ層->出力層重み * 隠れ層<-出力層での誤差
			sum += W10[j][i]*E10[j];
		}
		E9[i] = sum * activationFunc_diff(H9i[i]);
	}

	for(i=0;i<hiddennum8;i++){
		sum = 0;
		for(j=0;j<outputnum;j++){
			// 中間層での誤差信号=f'(隠れ層出力) * 隠れ層->出力層重み * 隠れ層<-出力層での誤差
			sum += W9[j][i]*E9[j];
		}
		E8[i] = sum * activationFunc_diff(H8i[i]);
	}

	for(i=0;i<hiddennum7;i++){
		sum = 0;
		for(j=0;j<outputnum;j++){
			// 中間層での誤差信号=f'(隠れ層出力) * 隠れ層->出力層重み * 隠れ層<-出力層での誤差
			sum += W8[j][i]*E8[j];
		}
		E7[i] = sum * activationFunc_diff(H7i[i]);
	}

	for(i=0;i<hiddennum6;i++){
		sum = 0;
		for(j=0;j<hiddennum7;j++){
			// 中間層での誤差信号=f'(隠れ層出力) * 隠れ層->出力層重み * 隠れ層<-出力層での誤差
			sum += W7[j][i]*E7[j];
		}
		E6[i] = sum * activationFunc_diff(H6i[i]);
	}

	for(i=0;i<hiddennum5;i++){
		sum = 0;
		for(j=0;j<hiddennum6;j++){
			// 中間層での誤差信号=f'(隠れ層出力) * 隠れ層->出力層重み * 隠れ層<-出力層での誤差
			sum += W6[j][i]*E6[j];
		}
		E5[i] = sum * activationFunc_diff(H5i[i]);
	}

	for(i=0;i<hiddennum4;i++){
		sum = 0;
		for(j=0;j<hiddennum5;j++){
			// 中間層での誤差信号=f'(隠れ層出力) * 隠れ層->出力層重み * 隠れ層<-出力層での誤差
			sum += W5[j][i]*E5[j];
		}
		E4[i] = sum * activationFunc_diff(H4i[i]);
	}

	for(i=0;i<hiddennum3;i++){
		sum = 0;
		for(j=0;j<hiddennum4;j++){
			// 中間層での誤差信号=f'(隠れ層出力) * 隠れ層->出力層重み * 隠れ層<-出力層での誤差
			sum += W4[j][i]*E4[j];
		}
		E3[i] = sum * activationFunc_diff(H3i[i]);
	}

	for(i=0;i<hiddennum2;i++){
		sum = 0;
		for(j=0;j<hiddennum3;j++){
			// 中間層での誤差信号=f'(隠れ層出力) * 隠れ層->出力層重み * 隠れ層<-出力層での誤差
			sum += W3[j][i]*E3[j];
		}
		E2[i] = sum * activationFunc_diff(H2i[i]);
	}

	for(i=0;i<hiddennum1;i++){
		sum = 0;
		for(j=0;j<hiddennum2;j++){
			// 中間層での誤差信号=f'(隠れ層出力) * 隠れ層->出力層重み * 隠れ層<-出力層での誤差
			sum += W2[j][i]*E2[j];
		}
		E1[i] = sum * activationFunc_diff(H1i[i]);
	}

	// 重みの更新
	for(i=0;i<outputnum;i++){
		for(j=0;j<hiddennum10;j++){
			W11[i][j] += ALPHA * H10i[j] * E11[i];
		}
		W11[i][hiddennum10] += ALPHA*(1.0)*E11[i];		// bias項
	}

	for(i=0;i<hiddennum10;i++){
		if(random() < DROPOUT){
			for(j=0;j<hiddennum9;j++){
				W10[i][j] += ALPHA * H9i[j] * E10[i];
			}
			W10[i][hiddennum9] += ALPHA*(1.0)*E10[i];		// bias項
		}
	}

	for(i=0;i<hiddennum9;i++){
		if(random() < DROPOUT){
			for(j=0;j<hiddennum8;j++){
				W9[i][j] += ALPHA * H8i[j] * E9[i];
			}
			W9[i][hiddennum8] += ALPHA*(1.0)*E9[i];		// bias項
		}
	}

	for(i=0;i<hiddennum8;i++){
		if(random() < DROPOUT){
			for(j=0;j<hiddennum7;j++){
				W8[i][j] += ALPHA * H7i[j] * E8[i];
			}
			W8[i][hiddennum7] += ALPHA*(1.0)*E8[i];		// bias項
		}
	}

	for(i=0;i<hiddennum7;i++){
		if(random() < DROPOUT){
			for(j=0;j<hiddennum6;j++){
				W7[i][j] += ALPHA * H6i[j] * E7[i];
			}
			W7[i][hiddennum6] += ALPHA*(1.0)*E7[i];		// bias項
		}
	}

	for(i=0;i<hiddennum6;i++){
		if(random() < DROPOUT){
			for(j=0;j<hiddennum5;j++){
				W6[i][j] += ALPHA * H5i[j] * E6[i];
			}
			W6[i][hiddennum5] += ALPHA*(1.0)*E6[i];		// bias項
		}
	}

	for(i=0;i<hiddennum5;i++){
		if(random() < DROPOUT){
			for(j=0;j<hiddennum4;j++){
				W5[i][j] += ALPHA * H4i[j] * E5[i];
			}
			W5[i][hiddennum4] += ALPHA*(1.0)*E5[i];		// bias項
		}
	}

	for(i=0;i<hiddennum4;i++){
		if(random() < DROPOUT){
			for(j=0;j<hiddennum3;j++){
				W4[i][j] += ALPHA * H3i[j] * E4[i];
			}
			W4[i][hiddennum3] += ALPHA*(1.0)*E4[i];		// bias項
		}
	}

	for(i=0;i<hiddennum3;i++){
		if(random() < DROPOUT){
			for(j=0;j<hiddennum2;j++){
				W3[i][j] += ALPHA * H2i[j] * E3[i];
			}
			W3[i][hiddennum2] += ALPHA*(1.0)*E3[i];		// bias項
		}
	}

	for(i=0;i<hiddennum2;i++){
		if(random() < DROPOUT){
			for(j=0;j<hiddennum1;j++){
				W2[i][j] += ALPHA * H1i[j] * E2[i];
			}
			W2[i][hiddennum1] += ALPHA*(1.0)*E2[i];		// bias項
		}
	}

	for(i=0;i<hiddennum1;i++){
		if(random() < DROPOUT){
			for(j=0;j<inputnum;j++){
				W1[i][j] += ALPHA * Ii[pnum][j] * E1[i];
			}
			W1[i][inputnum] += ALPHA*(1.0)*E1[i];		// bias項
		}
	}
}

void nnet::train()
{
	double verror;
	unsigned long gen;
	int i,j,ip;
	const double delta_err = 10e-7;

#if 1
	// 状態表示
	std::string str;
	for(i=0;i<patternnum;i++){
		str="";
		for(j=0;j<inputnum;j++){
			str += tostr(Ii[i][j]);
			str += ",";
		}
		str += ":";
		for(j=0;j<outputnum;j++){
			str+=tostr(Ti[i][j]);
		}
		outlog(str);
	}
#endif

	// 学習開始
	gen = 0;
	verror = 20.0;
	while((verror > ERROREV) && (gen < MAXGEN))
	{
		gen++;

		// foward and back propagation
		for(i=0;i<patternnum;i++){

			ip=i;
			
			foward_propagation(ip);
			back_propagation(ip);

		}

		// error calc
		verror = 0;
		for(i=0;i<patternnum;i++){
			foward_propagation(i);
			for(j=0;j<outputnum;j++){
				// --誤差関数
				// https://github.com/tiny-dnn/tiny-dnn/wiki/%E5%AE%9F%E8%A3%85%E3%83%8E%E3%83%BC%E3%83%88
				//verror+=pow((Ti[i][j] - Oi[j]) ,2.0) * 0.5;   // 二乗誤差
				//verror+= -Ti[i][j] * std::log(Oi[j]) - (1.0 - Ti[i][j]) * std::log(1.0 - Oi[j]);	// 交差エントロピー
				verror+= -Ti[i][j] * std::log(Oi[j] + delta_err); 												// 交差エントロピー（マルチクラス）
				// --
			}
		}
		verror /= (double)patternnum;

		outlog(verror);

	}
}

int nnet::predict(const int &pnum)
{

	foward_propagation(patternnum-1);

	double max = Oi[0];
	int maxarg = 0;

	for(int i=0;i<outputnum;i++){
		if(max<Oi[i]){
			max=Oi[i];
			maxarg=i;
		}
	}

	return maxarg;

}

double nnet::random()
{
	double r;
	int i;

	i = rand();
	if (i != 0){
		i--;
	}
	r = (double)i / RAND_MAX;
	return (r);
}

// Leaky Relu function
// alpha=0.001
double nnet::activationFunc(double x)
{
	return ((x >= 0)?  x : 0.1 * x);
}

double nnet::activationFunc_diff(double x)
{
	return ((x >= 0)?  1 : 0.1);
}


// 出力関数
//ソフトマックス関数
double nnet::outputFunc(const double& value,const std::vector<double>& x,int onum)
{
	double sum=0;
	double max = getMax(x);
	for(int i=0;i<onum;i++){
		sum+=std::exp(x[i]-max);
	}
	return std::exp(value-max) / sum;
}

double nnet::outputFunc_diff(double x)
{
	return 1;
}

double nnet::urand()
{
	return ((double) rand()/RAND_MAX * (RHIGH - RLOW) + RLOW);
}

void nnet::outlog(double value)
{
	//Form1->Memo1->Lines->Add(FloatToStr(value));
	std::cout << value << std::endl;
}

void nnet::outlog(std::string str)
{
	//Form1->Memo1->Lines->Add(str.c_str());
	std::cout << str << std::endl;
}

double nnet::getMax(const std::vector<double>& x)
{
	double temp = x[0];

	for(int i=0;i<(int)x.size();i++){
		if(x[i]>temp){
			temp=x[i];
		}
	}
	
	return temp;

}



int main()
{
  int i;
  double input[150][4];
  double teach[150];
  int accuracy = 0;
  int predict;

  nnet net(4,10,10,10,10,10,10,10,10,10,10,3,150);

  net.setAlpha(0.001);	// ReLu
  net.setErrorEv(0.05);

  //ファイルの読み込み
	std::stringstream ss;
	std::ifstream ifs("iris_norm.txt");
	if(!ifs){
        net.outlog("--  入力エラー --");
        return 0;
    }

    //csvファイルを1行ずつ読み込む
	std::string str;
	int inputnum;
	int cnt = 0;
	while(getline(ifs,str)){
		std::string token;
		std::istringstream stream(str);

		//1行のうち、文字列とコンマを分割する
		inputnum = 0;
		while(getline(stream,token,',')){
			//すべて文字列として読み込まれるため
			//数値は変換が必要
			if(inputnum < 4){

				// 文字列から数値に変換
				double temp;
				ss << token;
				ss >> temp;

				input[cnt][inputnum] = temp;

				ss.clear(); // 状態をクリア.
				ss.str(""); // 文字列をクリア.

				net.setInData(cnt,inputnum,temp);
			}else{
				if(token=="s"){
					net.setTeachData(cnt,0,1);
					net.setTeachData(cnt,1,0);
					net.setTeachData(cnt,2,0);
					teach[cnt]=0;
				}else if(token=="e"){
					net.setTeachData(cnt,0,0);
					net.setTeachData(cnt,1,1);
					net.setTeachData(cnt,2,0);
					teach[cnt]=1;
				}else{
					net.setTeachData(cnt,0,0);
					net.setTeachData(cnt,1,0);
					net.setTeachData(cnt,2,1);
					teach[cnt]=2;
				}
			}
			inputnum++;
		}
		cnt++;
	}

  net.train();


  net.outlog("--  Predict --");

  for(i=0;i<150;i++){
	net.setPredictData(0,input[i][0]);
	net.setPredictData(1,input[i][1]);
	net.setPredictData(2,input[i][2]);
	net.setPredictData(3,input[i][3]);
	predict = net.predict(i);
	std::cout << teach[i] << "->" << predict << std::endl;
	if(teach[i] == predict){
		accuracy++;
	}
  }

  std::cout << "accuracy:" << (double)accuracy / 150 << std::endl;

  return 0;

}

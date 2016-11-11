//---------------------------------------------------------------------------

#ifndef nnetH
#define nnetH

#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <ctime>        // time
#include <cstdlib>      // srand,rand
#include <fstream>
#include <string>
#include <sstream> //文字ストリーム


class nnet
{

	public:
		nnet(const int &inum,		// 入力層の数
			const int &hnum1,		// 隠れ層1の数
			const int &hnum2,		// 隠れ層2の数
			const int &hnum3,		// 隠れ層3の数
			const int &hnum4,
			const int &hnum5,
			const int &hnum6,
			const int &hnum7,
			const int &hnum8,
			const int &hnum9,
			const int &hnum10,		// 隠れ層10の数
			const int &onum,		// 出力層の数
			const int &pnum);		// データセット数
		~nnet();
		void setAlpha(const double &value);
		void setErrorEv(const double &value);
		void setInData(const int &pnum,const int &i,const double &value);
		void setTeachData(const int &pnum,const int &i,const double &value);
		void setPredictData(const int &i,const double &value);
		void train();
		int predict(const int &pnum);

		void outlog(std::string str);
		void outlog(double value);

	private:
		int inputnum;
		int hiddennum1;
		int hiddennum2;
		int hiddennum3;
		int hiddennum4;
		int hiddennum5;
		int hiddennum6;
		int hiddennum7;
		int hiddennum8;
		int hiddennum9;
		int hiddennum10;
		int outputnum;
		int patternnum;
		std::vector< std::vector<double> > Ii;					// 入力層
		std::vector<double> H1i;								// 隠れ層1
		std::vector<double> H2i;								// 隠れ層2
		std::vector<double> H3i;								// 隠れ層3
		std::vector<double> H4i;								// 隠れ層4
		std::vector<double> H5i;								// 隠れ層5
		std::vector<double> H6i;								// 隠れ層6
		std::vector<double> H7i;								// 隠れ層7
		std::vector<double> H8i;								// 隠れ層8
		std::vector<double> H9i;								// 隠れ層9
		std::vector<double> H10i;								// 隠れ層10
		std::vector<double> Oi;      							// 出力層
		std::vector< std::vector<double> > W1;					// 入力層->隠れ層重み(隠れ1×入力)
		std::vector< std::vector<double> > W2;					// 隠れ層->隠れ層重み(隠れ2×隠れ1)
		std::vector< std::vector<double> > W3;					// 隠れ層->隠れ層重み(隠れ3×隠れ2)
		std::vector< std::vector<double> > W4;
		std::vector< std::vector<double> > W5;
		std::vector< std::vector<double> > W6;
		std::vector< std::vector<double> > W7;
		std::vector< std::vector<double> > W8;
		std::vector< std::vector<double> > W9;
		std::vector< std::vector<double> > W10;
		std::vector< std::vector<double> > W11;					// 隠れ層->出力層重み(出力×隠れ10)

		// foward propagation
		std::vector< std::vector<double> > Ti;					// 教師信号

		// back propagation
		std::vector<double> E1;           					// 入力<-隠れ層1での誤差
		std::vector<double> E2;           					// 隠れ層1<-隠れ層2での誤差
		std::vector<double> E3;           					// 隠れ層2<-出力層での誤差
		std::vector<double> E4;
		std::vector<double> E5;
		std::vector<double> E6;
		std::vector<double> E7;
		std::vector<double> E8;
		std::vector<double> E9;
		std::vector<double> E10;
		std::vector<double> E11;

		// const parameter
		double ALPHA;
		double ERROREV;
		#define RLOW        -1				// 初期化最小値
		#define RHIGH       1				// 初期化最大値
		#define MAXGEN      200000			// 繰り返し最大数
		#define DROPOUT     0.5				// ドロップアウト率

		double activationFunc(double x);
		double activationFunc_diff(double x);
		double outputFunc(const double& value,const std::vector<double>& x,int onum);
		double outputFunc_diff(double x);

		// functions
		void foward_propagation(const int &pnum);
		void back_propagation(const int &pnum);
		double random();
		double urand();
		double getMax(const std::vector<double>& x);

		template <typename T> std::string tostr(const T& t)
		{
			std::ostringstream os; os<<t; return os.str();
		}



};

#endif

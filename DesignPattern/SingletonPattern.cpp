//
//  SingletonPattern.cpp
//  CppDpLearning
//
//  Created by SakuragiYoshimasa on 2016/02/18.
//  Copyright © 2016年 SakuragiYoshimasa. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

//インスタンスが一つしか存在しないオブジェクトを作る。
//言ってしまえばグローバル変数を作るようなものなので扱いに注意。先に他の方法を考える
//アクセスのコントロールが大事
//遅延インスタンス化できる
//マルチスレッドにするとインスタンスが増えるのでgetInstanceを同期メソッドにすると遅くなるので
//先行インスタンス化して複数のインスタンスができるのを防ぎ、同期メソッドにする必要もなくなる
//
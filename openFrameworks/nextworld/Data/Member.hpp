//
//  Member.hpp
//  20160222
//
//  Created by HirokiNaganuma on 2016/02/22.
//
//  Csvでは一人のデータ84の要素から成る
//
//

#ifndef Member_hpp
#define Member_hpp

#include "ofMain.h"
#include "Profile.h"


class Member{
    

public:
    int  id;
    string  name; //Family name : First name で分かれてる(漢字)
    string  kana_name; //Family name : First name で分かれてる(カタカナ)
    Course  course; //今回のコース
    Grade   grade; //高校一年とか書いてるのを正規化する必要あり
    int     birthday; //yyyy/mm/ddで正規化されてる
    Sex     sex; //性別
    Address address; //郵便番号のint型変数をAdress内に持たせる
    

    Member(){};

    Member(int id, string family_name, string first_name,string family_kananame,string first_kananame, Course cource, Grade grade, Sex sex, Address address){
        this->id = id;
        this->name = family_name + first_name;
        this->kana_name = family_kananame + first_kananame;
        this->course = cource;
        this->grade = grade;
        this->sex = sex;
        this->address = address;
    };

    
    Member(int id, Course course, Grade grade, Sex sex, string address){
        this->id = id;
        this->course = course;
        this->grade = grade;
        this->sex = sex;
    }
    void update();
    void draw();
};

/*

 0      string id;
 1      string plan;
 2-3    string name; //Family name : First name で分かれてる(漢字)
 4-5    string kana_name; //Family name : First name で分かれてる(カタカナ)
 6      string course; //今回のコース
 7      string _plan; //宿泊とか通いとか
 8      bool   is_rental;
 9      string pc_name;
 10     string school_name;
 11     int    grade; //高校一年とか書いてるのを正規化する必要あり
 12     int    birthday; //yyyy/mm/ddで正規化されてる
 13     bool   sex; //性別
 14     string allergy; //アレルギー
 15     string taking_medicine; //服薬
 16     string health; //健康状態など
 17     string question; //質問事項など
 18     string same_team_member; //同じ班にしてほしい子などの希望
 19-37  struct num_course_ent cources; //各コースに何回来ているかなど
 38     string production_exp; //制作経験など
 39     string parent_name;
 40     string parent_name_kana;
 41     string phone_number1;
 42     string phone_number2;
 43     string mail_address;
 44     string zipcode; //郵便番号int型にしたほうが良い？
 45     string address;
 46     string relation;
 47     string delay_info;
 48     string comment;
 49     string member_phone_number;
 50     string trigger;
 51-84    struct num_camp_ent camp;//ここは無視
 
 struct num_course_ent {//コース何回来たのかの構造体の定義
 int n_iphone;
 int n_android;
 int n_win;
 int n_web_d;
 int n_web_p;
 int n_2d_game;
 int n_enchant;
 int n_3d_game;
 int n_animation;
 int n_media_art;
 int n_designer;
 int n_movie_edit;
 int n_music;
 int n_animation_design;
 int n_win_8;
 int n_unity;
 int n_minecraft;
 int n_line_stamp;
 int n_miku;
 };
 
 struct num_camp_ent {//どのキャンプ来たのかの構造体の定義
 int camp[34];
 };
 
 */


#endif /* Member_hpp */

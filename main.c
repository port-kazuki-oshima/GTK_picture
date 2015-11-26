/* 
 * File:   main.c
 * Author: kazuki-oshima
 *
 * Created on 2015/11/21, 6:05
 */

#include<gtk/gtk.h>
/*
 * 
 */

int main(int argc, char** argv) {
    
    GtkWidget *window;
    
    /* GTK+の初期化およびオプション解析*/
    gtk_init(&argc,&argv);
    
    /*ウィンドウの作成*/
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    
    /*ウィンドウの大きさの指定*/
    //第一引数に上記のwindowを入れて、第二第三にサイズを指定
    gtk_widget_set_size_request(window,1000,200);
    
    /* ウィンドウの表示 */
    gtk_widget_show(window);
    
    /* メインループ */
    gtk_main();
    
    
    return 0;
}



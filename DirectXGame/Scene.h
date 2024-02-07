#pragma once

//メインのシーン切り替えで使う
enum class SceneType 
{
	kTitle,	//タイトルシーン
	kGame,  //ゲームプレイシーン
	kClear,	//ゲームクリアシーン
	kOver,	//ゲームオーバーシーン
};

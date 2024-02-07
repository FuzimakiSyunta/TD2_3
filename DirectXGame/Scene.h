#pragma once

//メインのシーン切り替えで使う
enum class SceneType 
{
	kTitle,	//タイトルシーン
	kEx, //説明シーン
	kGame,  //ゲームプレイシーン
	kClear,	//ゲームクリアシーン
	kOver,	//ゲームオーバーシーン
};

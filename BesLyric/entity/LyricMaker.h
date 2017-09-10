/*
	BesLyric  һ�� �����򵥡�����ʵ�õ� ר�������������������ֹ�����ʵ� �������������
    Copyright (C) 2017  
	Author: BensonLaur <BensonLaur@163.com>
	Author:

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
* @file       LyricMaker.h
* 
* Describe    LyricMaker�࣬������ �������ҳ�洦�� ������������  LyricMaker�� �Ľӿ�	
*/

#pragma once
#include "stdafx.h"
#include "MusicPlayer.h"
#include <vector>
#include "../utility/WinFile.h"
#include  "PageSetting.h"
using namespace std;

/*
*	@brief ������������洢�ʹ��� �������������ʹ�õ�������
*/
class LyricMaker
{
public:
	LyricMaker();
	void Init(CSettingPage *pSettingPage);		//��ʼ��ʱ�õ�������ָ��

	//���ø���·��
	//��������·��ʱ�����벥��������Ҫ�� ��Ϣ�������ڵľ��
	void setMusicPath(LPCTSTR pathName,HWND hostWnd);
	
	void setLyricPath(LPCTSTR pathName);
	
	void setm_szOutputPath(LPCTSTR pathName);
	
	//���� LyricMaker�� �������Ϊ��, ����������ļ���
	void reloadMaker();

	//������ʼ,��¼��ʼ������ʱ��
	//�ɹ����ŷ���true����Ҫת����ʽ����false
	bool makingStart();

	//Ϊ��һ�и�� ����� ����������Ҫ��� ʱ�����ʽ��д��m_vLyricOutput��
	void markNextLine();

	//�����һ�в��ǿհ��еĻ�,����
	void markSpaceLine();

	//�� m_vLyricOutput д������ļ�m_szOutputPathName ��
	void makingEnd();


	//���ݵ�ǰ����λ�ã����½�������ĸ������
	void RecorrectLyricData();

	//���ԭʼ���(��������Ŀ���)��nPos �ӵ�1�п�ʼ
	SStringW GetOriginLyricAt(std::size_t nPos);


	//��õ�ǰ����� �ļ���
	void getOutputFileName(TCHAR* name, int lenth = _MAX_FNAME);

	//��õ�ǰ����� ·���ļ���
	void getm_szOutputPathName(TCHAR* name, int lenth = _MAX_PATH);
	
	//�������ֲ���
	void stopMusic();

	//��������һ�е�״̬���Ƿ�Ϊ�հ���
	void setLastLineSpace(bool value);

	//��һ���Ƿ�Ϊ�հ���
	bool isLastLineSpace();

public:
	//���ļ���ȡÿ�и�ʵļ�������
	vector<SStringT> getLyricOrigin(File& encodingFile);

private:
	//����m_szMusicPathName ���ļ����õ�����ļ�����������outputFileName �� m_szOutputPathName��ֵ
	void generateOutputFileName();

	//�������ֵʱ�� ת��Ϊ���ʱ���ʽ ��[00:33.490] Look at the stars��
	//�� [00:33.490] ��ʽ����� timeBuf
	void msToLyricTimeString(int ms, LPTSTR timeBuf);

	//�������� �ɹ���ʼ���ŷ���true�� ��Ҫת����ʽ����false;
	bool playMusic();

public:
	TCHAR m_szMusicPathName[_MAX_PATH];			/*��� ѡ�� �������ӽ���ѡ���·����*/
	TCHAR m_szLyricPathName[_MAX_PATH];
	TCHAR m_szOutputPath[_MAX_PATH];

	TCHAR m_szOutputPathName[_MAX_PATH];		/*����ļ����ļ� ·�������� */

	vector<SStringT> m_vLyricOriginWithEmptyLine; /* ���п��е�ԭ��� */
	vector<SStringT> m_vLyricOrigin;			/* ����ԭ����ļ� ����һ�д���λ��Ϊ 0 ���� 1��*/
	vector<SStringT> m_vLyricOutput;			/* �����������ļ� */

	int				m_nCurLine;				/* ��ǰ��������� (��һ��Ϊ��1 ���� 0)*/
	int				m_nTotalLine;			/* ��������������������У� */
	
	MusicPlayer		m_musicPlayer;			/* �������������������ֵĲ��� */

private:
	CSettingPage *m_pSettingPage;			/* ����ҳ��ָ�� */

	TCHAR outputFileName[_MAX_FNAME];		/* ����ļ����ļ��� */

	
	bool			m_bLastLineSpace;		/* ��ǰ���Ƿ��ǿտհ��У��������ӿհ��У����Ƿǿ���֮��Զ�ֻ����һ�пհ��� */

};
//-----------------------------------------------------------------------------
// File: Matrices.cpp
//
// Desc: Now that we know how to create a device and render some 2D vertices,
//       this tutorial goes the next step and renders 3D geometry. To deal with
//       3D geometry we need to introduce the use of 4x4 matrices to transform
//       the geometry with translations, rotations, scaling, and setting up our
//       camera.
//
//       Geometry is defined in model space. We can move it (translation),
//       rotate it (rotation), or stretch it (scaling) using a world transform.
//       The geometry is then said to be in world space. Next, we need to
//       position the camera, or eye point, somewhere to look at the geometry.
//       Another transform, via the view matrix, is used, to position and
//       rotate our view. With the geometry then in view space, our last
//       transform is the projection transform, which "projects" the 3D scene
//       into our 2D viewport.
//
//       Note that in this tutorial, we are introducing the use of D3DX, which
//       is a set of helper utilities for D3D. In this case, we are using some
//       of D3DX's useful matrix initialization functions. To use D3DX, simply
//       include <d3dx9.h> and link with d3dx9.lib.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//-----------------------------------------------------------------------------

#include <Windows.h>
#include <mmsystem.h>
#include <d3dx9.h>
#include <stdio.h>

HWND hWnd ;


//-----------------------------------------------------------------------------
// Global variables
//-----------------------------------------------------------------------------
LPDIRECT3D9             g_pD3D       = NULL; // Used to create the D3DDevice
LPDIRECT3DDEVICE9       g_pd3dDevice = NULL; // Our rendering device
LPDIRECT3DVERTEXBUFFER9 g_pVB        = NULL; // Buffer to hold vertices

// A structure for our custom vertex type
struct CUSTOMVERTEX
{
    FLOAT x, y, z;      // The untransformed, 3D position for the vertex
    DWORD color;        // The vertex color
};

CUSTOMVERTEX P[8]; // 육면체 8개의 꼭지점의 좌표

CUSTOMVERTEX C[36]; // 육면체를 표현하기 위한 삼각형 버텍스의 갯수




// Our custom FVF, which describes our custom vertex structure
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE)

class C3DCube
{
private:
    UCHAR LC, HC; //low color, high color

    // t 위치 부터 삼각형 그리기 위한 버텍스 배열시킴
    VOID AV( UINT T, CUSTOMVERTEX T1, CUSTOMVERTEX T2, CUSTOMVERTEX T3 ); 
	HRESULT InitGeometry( void );

public:
	C3DCube(){};
	~C3DCube(){};
	HRESULT InitD3D( HWND hWnd );
	VOID Cleanup();
	VOID SetupMatrices();
	VOID Render();

    // 필수사항 이것은 반드시 지정해야 함.
    VOID SetColorRange( UCHAR LowColor, UCHAR HighColor ); // 색상을 랜덤으로 지정하는 값의 범위

    // 선택사항 1 : 여기서 시작해도 됨
    VOID Set8PointsBy1Line( FLOAT WIDTH ); // 1개의 길이로 8개의 지점값 생성

    // 선택사항 2 : 여기서 시작해도 됨
    VOID Set8PointsBy3Lines( FLOAT WIDTH, FLOAT HEIGHT, FLOAT DEPTH ); // 3개의 길이로 8개의 지점값 생성
    
    // 선택사항 3 : 여기서 시작해도 됨, 단, 8개의 좌표값을 수동이나 프로그램으로 먼저 입력해주어야 함.
    VOID Set36Verticesby8points( CUSTOMVERTEX *G ); // 8개의 지점값으로 36개의 버텍스데이타 생성
};

C3DCube C3DC;

VOID C3DCube::SetColorRange( UCHAR LowColor, UCHAR HighColor )
{
    LC = LowColor;
    HC = HighColor;
}

VOID C3DCube::Set8PointsBy1Line(FLOAT WIDTH)
{
    Set8PointsBy3Lines( WIDTH, WIDTH, WIDTH );
}

VOID C3DCube::Set8PointsBy3Lines(FLOAT WIDTH, FLOAT HEIGHT, FLOAT DEPTH)
{
    P[0].x = -1.0F * (WIDTH/2);
    P[1].x =  1.0F * (WIDTH/2);
    P[2].x = -1.0F * (WIDTH/2);
    P[3].x =  1.0F * (WIDTH/2);

    P[4].x =  1.0F * (WIDTH/2);
    P[5].x = -1.0F * (WIDTH/2);
    P[6].x =  1.0F * (WIDTH/2);
    P[7].x = -1.0F * (WIDTH/2);

    P[0].y =  1.0F * (HEIGHT/2);
    P[1].y =  1.0F * (HEIGHT/2);
    P[2].y = -1.0F * (HEIGHT/2);
    P[3].y = -1.0F * (HEIGHT/2);

    P[4].y =  1.0F * (HEIGHT/2);
    P[5].y =  1.0F * (HEIGHT/2);
    P[6].y = -1.0F * (HEIGHT/2);
    P[7].y = -1.0F * (HEIGHT/2);

    P[0].z = -1.0F * (DEPTH/2);
    P[1].z = -1.0F * (DEPTH/2);
    P[2].z = -1.0F * (DEPTH/2);
    P[3].z = -1.0F * (DEPTH/2);

    P[4].z =  1.0F * (DEPTH/2);
    P[5].z =  1.0F * (DEPTH/2);
    P[6].z =  1.0F * (DEPTH/2);
    P[7].z =  1.0F * (DEPTH/2);

    P[0].color = D3DCOLOR_XRGB( rand()%(HC-LC)+LC, rand()%(HC-LC)+LC, rand()%(HC-LC)+LC);
    P[1].color = D3DCOLOR_XRGB( rand()%(HC-LC)+LC, rand()%(HC-LC)+LC, rand()%(HC-LC)+LC);
    P[2].color = D3DCOLOR_XRGB( rand()%(HC-LC)+LC, rand()%(HC-LC)+LC, rand()%(HC-LC)+LC);
    P[3].color = D3DCOLOR_XRGB( rand()%(HC-LC)+LC, rand()%(HC-LC)+LC, rand()%(HC-LC)+LC);

    P[4].color = D3DCOLOR_XRGB( rand()%(HC-LC)+LC, rand()%(HC-LC)+LC, rand()%(HC-LC)+LC);
    P[5].color = D3DCOLOR_XRGB( rand()%(HC-LC)+LC, rand()%(HC-LC)+LC, rand()%(HC-LC)+LC);
    P[6].color = D3DCOLOR_XRGB( rand()%(HC-LC)+LC, rand()%(HC-LC)+LC, rand()%(HC-LC)+LC);
    P[7].color = D3DCOLOR_XRGB( rand()%(HC-LC)+LC, rand()%(HC-LC)+LC, rand()%(HC-LC)+LC);
    

}

VOID C3DCube::Set36Verticesby8points( CUSTOMVERTEX *G ) // 8개의 지점값으로 36개의 버텍스데이타 생성
{


	if( g_pVB != NULL )
		g_pVB->Release();

    AV( 0, G[5], G[4], G[1] );
    AV( 3, G[1], G[0], G[5] );
    AV( 6, G[5], G[0], G[2] );
    AV( 9, G[2], G[7], G[5] );
    AV( 12, G[0], G[1], G[3] );
    AV( 15, G[3], G[2], G[0] );
    AV( 18, G[1], G[4], G[6] );
    AV( 21, G[6], G[3], G[1] );
    AV( 24, G[4], G[5], G[7] );
    AV( 27, G[7], G[6], G[4] );
    AV( 30, G[2], G[3], G[6] );
    AV( 33, G[6], G[7], G[2] );

    InitGeometry();
}

VOID C3DCube::AV( UINT T, CUSTOMVERTEX T1, CUSTOMVERTEX T2, CUSTOMVERTEX T3 ) 
{
      C[T].x = T1.x;
      C[T+1].x = T2.x;
      C[T+2].x = T3.x;
  
      C[T].y = T1.y;
      C[T+1].y = T2.y;
      C[T+2].y = T3.y;

      C[T].z = T1.z;
      C[T+1].z = T2.z;
      C[T+2].z = T3.z;

      C[T].color = T1.color;
      C[T+1].color = T2.color;
      C[T+2].color = T3.color;
}

//-----------------------------------------------------------------------------
// Name: InitD3D()
// Desc: Initializes Direct3D
//-----------------------------------------------------------------------------
HRESULT C3DCube::InitD3D( HWND hWnd )
{
    // Create the D3D object.
    if( NULL == ( g_pD3D = Direct3DCreate9( D3D_SDK_VERSION ) ) )
        return E_FAIL;

    // Set up the structure used to create the D3DDevice
    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory( &d3dpp, sizeof(d3dpp) );
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

    // Create the D3DDevice
    if( FAILED( g_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
                                      D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                                      &d3dpp, &g_pd3dDevice ) ) )
    {
        return E_FAIL;
    }

    // Turn off culling, so we see the front and back of the triangle
    g_pd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_CCW );

    // Turn off D3D lighting, since we are providing our own vertex colors
    g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, FALSE );

    return S_OK;
}




//-----------------------------------------------------------------------------
// Name: InitGeometry()
// Desc: Creates the scene geometry
//-----------------------------------------------------------------------------
HRESULT C3DCube::InitGeometry()
{
    // Initialize three vertices for rendering a triangle




    /*CUSTOMVERTEX g_Vertices[] =
    {
		{  1.0f,-1.0f, 1.0f, 0xff0000ff, },
        { -1.0f,-1.0f, 1.0f, 0xffff0000, },
        {  0.0f, 1.0f, 1.0f, 0xffffffff, },
    };
    */

    // Create the vertex buffer.
    if( FAILED( g_pd3dDevice->CreateVertexBuffer( 36*sizeof(CUSTOMVERTEX),
                                                  0, D3DFVF_CUSTOMVERTEX,
                                                  D3DPOOL_DEFAULT, &g_pVB, NULL ) ) )
    {
        return E_FAIL;
    }

    // Fill the vertex buffer.
    VOID* pVertices;
    if( FAILED( g_pVB->Lock( 0, 0, (void**)&pVertices, 0 ) ) ) // ( 0, sizeof(C), (void**)&pVertices, 0 ) ) )
        return E_FAIL;
    memcpy( pVertices, C, 36*sizeof(CUSTOMVERTEX) );
    g_pVB->Unlock();

    return S_OK;
}




//-----------------------------------------------------------------------------
// Name: Cleanup()
// Desc: Releases all previously initialized objects
//-----------------------------------------------------------------------------
VOID C3DCube::Cleanup()
{
    if( g_pVB != NULL )
        g_pVB->Release();

    if( g_pd3dDevice != NULL )
        g_pd3dDevice->Release();

    if( g_pD3D != NULL )
        g_pD3D->Release();
}



//-----------------------------------------------------------------------------
// Name: SetupMatrices()
// Desc: Sets up the world, view, and projection transform matrices.
//-----------------------------------------------------------------------------
VOID C3DCube::SetupMatrices()
{
    // Set up our view matrix. A view matrix can be defined given an eye point,
    // a point to lookat, and a direction for which way is up. Here, we set the
    // eye five units back along the z-axis and up three units, look at the
    // origin, and define "up" to be in the y-direction.
    D3DXVECTOR3 vEyePt( 0.0f, 3.0f,-5.0f );
    D3DXVECTOR3 vLookatPt( 0.0f, 0.0f, 0.0f );
    D3DXVECTOR3 vUpVec( 0.0f, 1.0f, 0.0f );
    D3DXMATRIXA16 matView;
    D3DXMatrixLookAtLH( &matView, &vEyePt, &vLookatPt, &vUpVec );
    g_pd3dDevice->SetTransform( D3DTS_VIEW, &matView );

    // For the projection matrix, we set up a perspective transform (which
    // transforms geometry from 3D view space to 2D viewport space, with
    // a perspective divide making objects smaller in the distance). To build
    // a perpsective transform, we need the field of view (1/4 pi is common),
    // the aspect ratio, and the near and far clipping planes (which define at
    // what distances geometry should be no longer be rendered).
    D3DXMATRIXA16 matProj;
    D3DXMatrixPerspectiveFovLH( &matProj, D3DX_PI/4, 1.0f, 1.0f, 100.0f );
    g_pd3dDevice->SetTransform( D3DTS_PROJECTION, &matProj );
}



//-----------------------------------------------------------------------------
// Name: Render()
// Desc: Draws the scene
//-----------------------------------------------------------------------------
VOID C3DCube::Render()
{
   

    // Begin the scene
    if( SUCCEEDED( g_pd3dDevice->BeginScene() ) )
    {
        // Setup the world, view, and projection matrices
        SetupMatrices();

		// Clear the backbuffer to a black color
		g_pd3dDevice->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0,0,0), 1.0f, 0 );

		// For our world matrix, we will just rotate the object about the y-axis.
		D3DXMATRIXA16 matWorld;
		// Set up the rotation matrix to generate 1 full rotation (2*PI radians) 
		// every 1000 ms. To avoid the loss of precision inherent in very high 
		// floating point numbers, the system time is modulated by the rotation 
		// period before conversion to a radian angle.
		UINT  ct = timeGetTime();
		/* char aa[20]={NULL,};
		sprintf( aa, "%d ", ct );
		SetWindowText( hWnd, aa );*/
		UINT  iTime  = timeGetTime() % 5000;
		FLOAT fAngle = iTime * (2.0f * D3DX_PI) / 5000.0f;
		D3DXMatrixRotationY( &matWorld, fAngle );// 0.0f );
		char aa[20]={NULL,};
		sprintf( aa, "%d & %d ", iTime, ct );
		SetWindowText( hWnd, aa );
		g_pd3dDevice->SetTransform( D3DTS_WORLD, &matWorld );


        // Render the vertex buffer contents
        g_pd3dDevice->SetStreamSource( 0, g_pVB, 0, sizeof(CUSTOMVERTEX) );
        g_pd3dDevice->SetFVF( D3DFVF_CUSTOMVERTEX );
        g_pd3dDevice->DrawPrimitive( D3DPT_TRIANGLELIST, 0, 36 );

        // End the scene
        g_pd3dDevice->EndScene();
    }

    // Present the backbuffer contents to the display
    g_pd3dDevice->Present( NULL, NULL, NULL, NULL );
}




//-----------------------------------------------------------------------------
// Name: MsgProc()
// Desc: The window's message handler
//-----------------------------------------------------------------------------
LRESULT WINAPI MsgProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    switch( msg )
    {
        case WM_DESTROY:
            C3DC.Cleanup();
            PostQuitMessage( 0 );
            return 0;
    }

    return DefWindowProc( hWnd, msg, wParam, lParam );
}




//-----------------------------------------------------------------------------
// Name: WinMain()
// Desc: The application's entry point
//-----------------------------------------------------------------------------
INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR, INT )
{
    // Register the window class
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L,
                      GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
                      "D3D Tutorial", NULL };
    RegisterClassEx( &wc );

    // Create the application's window
    hWnd = CreateWindow( "D3D Tutorial", "D3D Tutorial 03: Matrices",
                              WS_OVERLAPPEDWINDOW, 100, 100, 512, 512,
                              GetDesktopWindow(), NULL, wc.hInstance, NULL );

    // Initialize Direct3D
    if( SUCCEEDED( C3DC.InitD3D( hWnd ) ) )
    {
        // Create the scene geometry

        
        // Show the window
        ShowWindow( hWnd, SW_SHOWDEFAULT );
        UpdateWindow( hWnd );

		C3DC.SetColorRange( 0, 254 ); // 색상을 랜덤으로 지정하는 값의 범위
		C3DC.Set8PointsBy1Line( 2.0F ); // 1개의 길이로 8개의 지점값 생성
		// C3DC.Set8PointsBy3Lines( 2.0F, 1.0F, 1.0F ); // 1개의 길이로 8개의 지점값 생성
		// 여기서 8개 지점좌표를 임의로 수정할 수 있다.
		//        P[0].x = -1.8F;
		//        P[0].y = 1.8F;
		C3DC.Set36Verticesby8points( P ); // 실제로 8개의 좌표를 36개로 옮겨준다.

        // Enter the message loop
        MSG msg;
        ZeroMemory( &msg, sizeof(msg) );
        while( msg.message!=WM_QUIT )
        {
            if( PeekMessage( &msg, NULL, 0U, 0U, PM_REMOVE ) )
            {
                TranslateMessage( &msg );
                DispatchMessage( &msg );
            }
            else
			{
               C3DC.Render();
			}
        }
        
    }

    UnregisterClass( "D3D Tutorial", wc.hInstance );
    return 0;
}

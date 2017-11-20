<GameFile>
  <PropertyGroup Name="triangleNode" Type="Node" ID="c51bf27b-734d-4434-8ed9-2855bb665358" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="35" Speed="1.0000">
        <Timeline ActionTag="1175347666" Property="Alpha">
          <IntFrame FrameIndex="0" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="15" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="27" Value="127">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="35" Value="255">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="1409187612" Property="Alpha">
          <IntFrame FrameIndex="0" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="3" Value="22">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="11" Value="22">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="35" Value="255">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="-345437346" Property="Alpha">
          <IntFrame FrameIndex="0" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="3" Value="76">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="11" Value="76">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="35" Value="255">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="-1994784246" Property="FileData">
          <TextureFrame FrameIndex="0" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_00.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="3" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_01.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="7" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_02.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="11" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_00.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="15" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_04.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="19" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_05.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="23" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_06.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="27" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_06.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="31" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_02.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="35" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_00.png" Plist="scene101.plist" />
          </TextureFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="triRoot" Tag="15" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="trishadow_1" ActionTag="1175347666" Alpha="10" Tag="11" IconVisible="False" LeftMargin="-68.1924" RightMargin="-68.8076" TopMargin="-23.2300" BottomMargin="0.2300" ctype="SpriteObjectData">
            <Size X="137.0000" Y="23.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="0.3076" Y="11.7300" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="PlistSubImage" Path="trishadow.png" Plist="scene101.plist" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="triblock" ActionTag="1409187612" Alpha="70" Tag="85" IconVisible="False" LeftMargin="-84.0000" RightMargin="-84.0000" TopMargin="-172.0000" BottomMargin="28.0000" ctype="SpriteObjectData">
            <Size X="168.0000" Y="144.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position Y="100.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="PlistSubImage" Path="triblock.png" Plist="scene101.plist" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="triOuter" ActionTag="-345437346" Alpha="113" Tag="84" IconVisible="False" LeftMargin="-85.5000" RightMargin="-85.5000" TopMargin="-192.0000" BottomMargin="24.0000" ctype="SpriteObjectData">
            <Size X="171.0000" Y="168.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position Y="108.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="PlistSubImage" Path="triouter.png" Plist="scene101.plist" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="fire" ActionTag="-1994784246" Tag="83" IconVisible="False" LeftMargin="-120.0000" RightMargin="-120.0000" TopMargin="-210.0000" BottomMargin="-10.0000" ctype="SpriteObjectData">
            <Size X="240.0000" Y="220.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position Y="100.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="PlistSubImage" Path="flame1_04.png" Plist="scene101.plist" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>
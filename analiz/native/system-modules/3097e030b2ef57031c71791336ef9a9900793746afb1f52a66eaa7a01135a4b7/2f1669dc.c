
/* porting_InternalSubtitleRender::SetFTFace(FT_FaceRec_*) */

void porting_InternalSubtitleRender::SetFTFace(FT_FaceRec_ *param_1)

{
  *(FT_FaceRec_ **)PTR_pRenderFTFace_2f18b0dc = param_1;
  return;
}


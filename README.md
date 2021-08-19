# TestITKNIFTI

Testing the sform fix for ITK

https://github.com/InsightSoftwareConsortium/ITK/pull/2701

to build:

```
cmake -D ITK_DIR=/path/to/ITK_build /path/to/repo
make
```

to run:

```
./itk_image_read oneMuM.nii.gz
./itk_image_read oneMuMNoQForm.nii.gz
```

The program should read both if linked to ITK with the proposed fix. Code built with ITK 5.2
(eg, ANTs PrintHeader) will refuse to read the one without the qform.

The two test images are identical except for the presence of the qform fields. A
header dump diff from `c3d`:

```
Image #1:							Image #1:
  Image Dimensions   : [100, 100, 100]				  Image Dimensions   : [100, 100, 100]
  Bounding Box       : {[0.03 0.04 0.025], [0.08 0.09 0.125]}	  Bounding Box       : {[0.03 0.04 0.025], [0.08 0.09 0.125]}
  Voxel Spacing      : [0.0005, 0.0005, 0.001]			  Voxel Spacing      : [0.0005, 0.0005, 0.001]
  Intensity Range    : [0, 0]					  Intensity Range    : [0, 0]
  Mean Intensity     : 0					  Mean Intensity     : 0
  Canon. Orientation : RAI					  Canon. Orientation : RAI
  Direction Cos Mtx. : 						  Direction Cos Mtx. :
    1.0000     0.0000     0.0000 				    1.0000     0.0000     0.0000
    0.0000     1.0000     0.0000 				    0.0000     1.0000     0.0000
    0.0000     0.0000     1.0000 				    0.0000     0.0000     1.0000
  Voxel->RAS x-form  : 						  Voxel->RAS x-form  :
        -0.00050     -0.00000     -0.00000     -0.03000 	        -0.00050     -0.00000     -0.00000     -0.03000
        -0.00000     -0.00050     -0.00000     -0.04000 	        -0.00000     -0.00050     -0.00000     -0.04000
         0.00000      0.00000      0.00100      0.02500 	         0.00000      0.00000      0.00100      0.02500
         0.00000      0.00000      0.00000      1.00000 	         0.00000      0.00000      0.00000      1.00000
  Image Metadata: 						  Image Metadata:
    bitpix = 32							    bitpix = 32
    cal_max = 0							    cal_max = 0
    cal_min = 0							    cal_min = 0
    datatype = 16						    datatype = 16
    dim[0] = 3							    dim[0] = 3
    dim[1] = 100						    dim[1] = 100
    dim[2] = 100						    dim[2] = 100
    dim[3] = 100						    dim[3] = 100
    dim[4] = 1							    dim[4] = 1
    dim[5] = 1							    dim[5] = 1
    dim[6] = 1							    dim[6] = 1
    dim[7] = 1							    dim[7] = 1
    intent_code = 0						    intent_code = 0
    intent_p1 = 0						    intent_p1 = 0
    intent_p2 = 0						    intent_p2 = 0
    intent_p3 = 0						    intent_p3 = 0
    pixdim[0] = 1					      |	    pixdim[0] = 0
    pixdim[1] = 0.0005						    pixdim[1] = 0.0005
    pixdim[2] = 0.0005						    pixdim[2] = 0.0005
    pixdim[3] = 0.001						    pixdim[3] = 0.001
    pixdim[4] = 0						    pixdim[4] = 0
    pixdim[5] = 0						    pixdim[5] = 0
    pixdim[6] = 0						    pixdim[6] = 0
    pixdim[7] = 0						    pixdim[7] = 0
    qform_code = 1					      |	    qform_code = 0
    qform_code_name = NIFTI_XFORM_SCANNER_ANAT		      |	    qform_code_name = NIFTI_XFORM_UNKNOWN
    qoffset_x = -0.03					      |	    qoffset_x = 0
    qoffset_y = -0.04					      |	    qoffset_y = 0
    qoffset_z = 0.025					      |	    qoffset_z = 0
    quatern_b = 0						    quatern_b = 0
    quatern_c = 0						    quatern_c = 0
    quatern_d = 1					      |	    quatern_d = 0
    scl_inter = 0						    scl_inter = 0
    scl_slope = 1						    scl_slope = 1
    sform_code = 1						    sform_code = 1
    sform_code_name = NIFTI_XFORM_SCANNER_ANAT			    sform_code_name = NIFTI_XFORM_SCANNER_ANAT
    slice_duration = 0						    slice_duration = 0
    slice_end = 0						    slice_end = 0
    slice_start = 0						    slice_start = 0
    srow_x = -0.0005 0 0 -0.03					    srow_x = -0.0005 0 0 -0.03
    srow_y = 0 -0.0005 0 -0.04					    srow_y = 0 -0.0005 0 -0.04
    srow_z = 0 0 0.001 0.025					    srow_z = 0 0 0.001 0.025
    toffset = 0							    toffset = 0
    vox_offset = 352						    vox_offset = 352

```
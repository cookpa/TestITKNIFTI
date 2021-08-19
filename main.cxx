#include <cstdlib>
#include <string>
#include <iostream>
#include <itkImage.h>
#include <itkImageFileReader.h>
#include <itkImageFileWriter.h>
#include <itkImageRegionIterator.h>


using namespace std;

int main(int argc, char const *argv[])
{
  if(argc < 2)
  {
    std::cerr << "Missing input filename" << std::endl;
    return EXIT_FAILURE;
  }

  const int ImageDimension = 3;

  using inPixelType = float;
  using ImageType = itk::Image<inPixelType, ImageDimension>;
  using Readertype = itk::ImageFileReader<ImageType>;

  typename Readertype::Pointer Reader = Readertype::New();

  if( argc < 2 )
    {
    std::cout << "missing input image name" << std::endl;
    throw;
    }

  Reader->SetFileName(argv[1]);
  Reader->Update();

  std::cout << "DIM: " << ImageDimension << std::endl;
  std::cout << " Spacing " << Reader->GetOutput()->GetSpacing() << std::endl;
  std::cout << " Origin " << Reader->GetOutput()->GetOrigin() << std::endl;

  if( ImageDimension == 1 )
    {
    std::cout << " Size : " << Reader->GetOutput()->GetLargestPossibleRegion().GetSize()[0] << " " <<   std::endl;
    }
  else if( ImageDimension == 2 )
    {
    std::cout << " Size : " << Reader->GetOutput()->GetLargestPossibleRegion().GetSize()[0] << " "
             << Reader->GetOutput()->GetLargestPossibleRegion().GetSize()[1] << " " << std::endl;
    }
  else if( ImageDimension == 3 )
    {
    std::cout << " Size : " << Reader->GetOutput()->GetLargestPossibleRegion().GetSize()[0] << " "
             << Reader->GetOutput()->GetLargestPossibleRegion().GetSize()[1] << " " <<  " "
             << Reader->GetOutput()->GetLargestPossibleRegion().GetSize()[2] << std::endl;
    }
  else
    {
    std::cout << " Size : " << Reader->GetOutput()->GetLargestPossibleRegion().GetSize() << std::endl;
    }

  // Compute the bounding box
  vnl_vector<double> bb0, bb1, ospm;
  bb0.set_size(ImageDimension);
  bb1.set_size(ImageDimension);
  ospm.set_size(ImageDimension);
  for( size_t i = 0; i < ImageDimension; i++ )
    {
    bb0[i] = Reader->GetOutput()->GetOrigin()[i];
    bb1[i] = bb0[i] + Reader->GetOutput()->GetSpacing()[i] * Reader->GetOutput()->GetBufferedRegion().GetSize()[i];
    ospm[i] = -Reader->GetOutput()->GetOrigin()[i] / Reader->GetOutput()->GetSpacing()[i];
    }

  cout << "  Bounding Box       : " << "{[" << bb0 << "], [" << bb1 << "]}" << endl;
  cout << "  Direction Cos Mtx. : " << endl;
  std::cout << Reader->GetOutput()->GetDirection().GetVnlMatrix() << std::endl;

  return EXIT_SUCCESS;
}

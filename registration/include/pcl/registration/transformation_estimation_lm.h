/*
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2010, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 *
 */
#ifndef PCL_REGISTRATION_TRANSFORMATION_ESTIMATION_LM_H_
#define PCL_REGISTRATION_TRANSFORMATION_ESTIMATION_LM_H_

#include <pcl/registration/transformation_estimation.h>

namespace pcl
{
  namespace registration
  {
    /** @b TransformationEstimationLM implements Levenberg Marquardt-based
      * estimation of the transformation aligning the given correspondences in
      * target and input point cloud 
      * \author Radu B. Rusu
      * \ingroup registration
      */
    template <typename PointSource, typename PointTarget>
    class TransformationEstimationLM : public TransformationEstimation<PointSource, PointTarget>
    {
    public:
      TransformationEstimationLM () {};
      virtual ~TransformationEstimationLM () {};

      /** \brief Estimate a rigid rotation transformation between a source and a target point cloud using LM.
       * \param cloud_src the source point cloud dataset
       * \param cloud_tgt the target point cloud dataset
       * \param transformation_matrix the resultant transformation matrix
       */
      inline void
      estimateRigidTransformation (
          const pcl::PointCloud<PointSource> &cloud_src,
          const pcl::PointCloud<PointTarget> &cloud_tgt,
          Eigen::Matrix4f &transformation_matrix);

      /** \brief Estimate a rigid rotation transformation between a source and a target point cloud using LM.
       * \param cloud_src the source point cloud dataset
       * \param indices_src the vector of indices describing the points of interest in \a cloud_src
       * \param cloud_tgt the target point cloud dataset
       * \param transformation_matrix the resultant transformation matrix
       */
      inline void
      estimateRigidTransformation (
          const pcl::PointCloud<PointSource> &cloud_src,
          const std::vector<int> &indices_src,
          const pcl::PointCloud<PointTarget> &cloud_tgt,
          Eigen::Matrix4f &transformation_matrix);

      /** \brief Estimate a rigid rotation transformation between a source and a target point cloud using LM.
       * \param cloud_src the source point cloud dataset
       * \param indices_src the vector of indices describing the points of interest in \a cloud_src
       * \param cloud_tgt the target point cloud dataset
       * \param indices_tgt the vector of indices describing the correspondences of the interst points from \a indices_src
       * \param transformation_matrix the resultant transformation matrix
       */
      inline void
      estimateRigidTransformation (
          const pcl::PointCloud<PointSource> &cloud_src,
          const std::vector<int> &indices_src,
          const pcl::PointCloud<PointTarget> &cloud_tgt,
          const std::vector<int> &indices_tgt,
          Eigen::Matrix4f &transformation_matrix);

      /** \brief Estimate a rigid rotation transformation between a source and a target point cloud using LM.
       * \param cloud_src the source point cloud dataset
       * \param cloud_tgt the target point cloud dataset
       * \param correspondences the vector of correspondences between source and target point cloud
       * \param transformation_matrix the resultant transformation matrix
       */
      inline void
      estimateRigidTransformation (
          const pcl::PointCloud<PointSource> &cloud_src,
          const pcl::PointCloud<PointTarget> &cloud_tgt,
          const std::vector<pcl::Correspondence> &correspondences,
          Eigen::Matrix4f &transformation_matrix);
    };

  }
}

#include <pcl/registration/impl/transformation_estimation_lm.hpp>

#endif /* PCL_REGISTRATION_TRANSFORMATION_ESTIMATION_LM_H_ */


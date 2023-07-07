import { Injectable } from '@nestjs/common'
import { S3 } from 'aws-sdk'
import Multer from 'multer'
import { extname } from 'path'
import { Express } from 'express';

@Injectable()
export default class UploadAvatar {
  private s3: S3
  constructor() { this.s3 = new S3({ accessKeyId: process.env.AWS_ACCESS_KEY_ID, secretAccessKey: process.env.AWS_SECRET_ACCESS_KEY, region: process.env.AWS_REGION }) }
  async uploadFileToS3(bucketName: string, key: string, buffer: NodeJS.ReadableStream): Promise<string> {
    try {
        const uploadParams: AWS.S3.PutObjectRequest = { Bucket: bucketName, Key: key, Body: buffer, ACL: 'public-read' }
        const uploadResult = await this.s3.upload(uploadParams).promise()
        return uploadResult.Location
    }
    catch (err) { console.log(err); return null }
  }
}

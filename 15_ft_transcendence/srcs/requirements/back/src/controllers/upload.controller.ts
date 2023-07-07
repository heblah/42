import { UseInterceptors, UploadedFile, Controller, Post, Get, Res, Req, UseGuards } from '@nestjs/common'
import { Response, Request } from 'express'
import { JwtAuthGuard } from '../jwt/jwt.guard'
import { FileInterceptor } from '@nestjs/platform-express'
import UploadService from '../services/upload.service'
import prisma from '../../prisma/prisma.client'
import * as fs from 'fs'

@Controller('upload')
@UseGuards(JwtAuthGuard)
export class UploadController	{
constructor(private readonly uploader: UploadService) {}
    @Post('avatar')
    @UseInterceptors(FileInterceptor('image'))
    async uploadAvatarProfile(@UploadedFile() file: Express.Multer.File, @Req() req: Request, @Res() res: Response) {
        try {
            const stream = fs.createReadStream(file.path)
            const uploadedURL = await this.uploader.uploadFileToS3(process.env.AWS_S3_BUCKET_NAME, file.originalname, stream)
            console.log(`AVATAR UPDATE => ${uploadedURL}`)
            const user: any = req.user
            const updateUser = await prisma.user.update({ where: { id: user.id }, data: { imageLink: uploadedURL } })
            fs.unlinkSync(file.path)
            res.status(201).json({ newURL: uploadedURL })
        }
        catch (err) { console.log(err); res.status(404) }
    }
}
